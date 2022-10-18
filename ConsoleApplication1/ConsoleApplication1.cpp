// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <Windows.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

using namespace std;



class VisualCorArr
{
private:
	int size = 0;
	int* x;
	int* y;

	string** arrH1;
	string** arrH2;
	string** arrH3;
	string** arrH4;

	string sepSym = ".";
	string pointSym = "o";

	bool numberInOrder = false;

public:
	int maxN = 0;
	string** resDiagramNoStyle;

	vector<vector<string>> resDiagramFinaly;




	VisualCorArr(int x[], int y[], int size, bool numberInOrder = false, string sepSym = ".", string pointSym = "o")
	{
		if (numberInOrder == true)
		{
			this->numberInOrder = true;
		}

		this->sepSym = sepSym;
		this->pointSym = pointSym;

		this->size = size;
		this->x = new int[size];
		this->y = new int[size];

		for (int i = 0; i < this->size; i++)
		{
			this->x[i] = x[i];
		}

		for (int i = 0; i < this->size; i++)
		{
			this->y[i] = y[i];
		}


		int sMax = -9999;

		for (int i = 0; i < this->size; i++)
		{
			if (abs(this->x[i]) > sMax)
			{
				sMax = abs(this->x[i]);
			}
		}

		for (int i = 0; i < size; i++)
		{
			if (abs(this->y[i]) > sMax)
			{
				sMax = abs(this->y[i]);
			}
		}

		maxN = sMax + 1;

		arrH1 = new string * [maxN];
		arrH2 = new string * [maxN];
		arrH3 = new string * [maxN];
		arrH4 = new string * [maxN];
		resDiagramNoStyle = new string * [maxN * 2];


		for (int i = 0; i < maxN; i++)
		{
			arrH1[i] = new string[maxN];
		}

		for (int i = 0; i < maxN; i++)
		{
			arrH2[i] = new string[maxN];
		}

		for (int i = 0; i < maxN; i++)
		{
			arrH3[i] = new string[maxN];
		}

		for (int i = 0; i < maxN; i++)
		{
			arrH4[i] = new string[maxN];
		}

		for (int i = 0; i < maxN * 2; i++)
		{
			resDiagramNoStyle[i] = new string[maxN * 2];
		}


		this->fillArrSym(arrH1);
		this->fillArrSym(arrH2);
		this->fillArrSym(arrH3);
		this->fillArrSym(arrH4);


		this->visualArr();

	}

	~VisualCorArr()
	{
		delete[] x;
		delete[] y;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH1[i];
		}

		delete[] arrH1;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH2[i];
		}

		delete[] arrH2;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH3[i];
		}

		delete[] arrH3;

		for (int i = 0; i < maxN; i++)
		{
			delete[] arrH4[i];
		}

		delete[] arrH4;

		for (int i = 0; i < maxN; i++)
		{
			delete[] resDiagramNoStyle[i];
		}

		delete[] resDiagramNoStyle;


	}


private:

	void fillArrSym(string** arr)
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				arr[i][k] = this->sepSym;
			}
		}
	}


	void printArr(string** arr)
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				cout << arr[i][k] << " ";
			}

			cout << endl;
		}
	}


	void drawCorLine()
	{
		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				if (k == 0)
				{
					if (arrH1[i][k] == this->sepSym)
					{
						arrH1[i][k] = "|";
					}
				}

				if (i == maxN - 1)
				{
					if (arrH1[i][k] == this->sepSym)
					{
						arrH1[i][k] = "-";
					}
				}
			}
		}

		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				if (i == maxN - 1)
				{
					if (arrH2[i][k] == this->sepSym)
					{
						arrH2[i][k] = "-";
					}
				}
			}
		}

		for (int i = 0; i < maxN; i++)
		{
			for (int k = 0; k < maxN; k++)
			{
				if (k == 0)
				{
					if (arrH4[i][k] == this->sepSym)
					{
						arrH4[i][k] = "|";
					}
				}
			}
		}
	}

public:

	void visualArr()
	{

		int countCoor = 1;

		for (int i = 0; i < size; i++)
		{
			int x1 = x[i];
			int y1 = y[i];

			if (x1 >= 0 && y1 >= 0)
			{
				if (numberInOrder)
				{
					arrH1[maxN - 1 - y1][x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH1[maxN - 1 - y1][x1] = this->pointSym;
				}
			}
			else if (x1 < 0 && y1 >= 0)
			{
				if (numberInOrder)
				{
					arrH2[maxN - y1 - 1][maxN + x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH2[maxN - y1 - 1][maxN + x1] = this->pointSym;
				}
			}
			else if (x1 < 0 && y1 < 0)
			{
				if (numberInOrder)
				{
					arrH3[y1 * (-1) - 1][maxN + x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH3[y1 * (-1) - 1][maxN + x1] = this->pointSym;
				}
			}
			else if (x1 >= 0 && y1 < 0)
			{
				if (numberInOrder)
				{
					arrH4[y1 * (-1) - 1][x1] = to_string(countCoor);
					countCoor++;
				}
				else
				{
					arrH4[y1 * (-1) - 1][x1] = this->pointSym;
				}

			}

		}

		this->drawCorLine();


		for (int i = 0; i < maxN * 2; i++)
		{
			for (int k = 0; k < maxN * 2; k++)
			{
				if (i <= maxN - 1 && k <= maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH2[i][k];
				}
				else if (i <= maxN - 1 && k > maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH1[i][k - maxN];
				}
				else if (i > maxN - 1 && k <= maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH3[i - maxN][k];
				}
				else if (i > maxN - 1 && k >= maxN - 1)
				{
					resDiagramNoStyle[i][k] = arrH4[i - maxN][k - maxN];
				}
				else {
					resDiagramNoStyle[i][k] = "*";
				}
			}
		}



		vector<string> temp1;

		for (int i = 0; i < maxN * 2 * 2 + 1; i++)
		{
			temp1.push_back("-");

		}

		resDiagramFinaly.push_back(temp1);

		for (int i = 0; i < maxN * 2 - 1; i++)
		{
			vector<string> temp2;

			for (int k = 0; k < maxN * 2; k++)
			{
				if (k == 0)
				{
					temp2.push_back("|");
				}
				else if (i == maxN * 2 - 1)
				{
					temp2.push_back("-");
				}
				else
				{
					temp2.push_back(resDiagramNoStyle[i][k]);
				}

				temp2.push_back(" ");

			}

			temp2.push_back("|");

			resDiagramFinaly.push_back(temp2);

		}

		vector<string> temp3;
		for (int i = 0; i < maxN * 2 * 2 + 1; i++)
		{
			temp3.push_back("-");
		}
		resDiagramFinaly.push_back(temp3);


		for (int i = 0; i < resDiagramFinaly[0].size(); i++)
		{
			if (resDiagramFinaly[resDiagramFinaly.size() / 2][i] == " ")
			{
				resDiagramFinaly[resDiagramFinaly.size() / 2][i] = "-";
			}
		}




	}

	string result()
	{
		string st = "";

		for (int i = 0; i < resDiagramFinaly.size(); i++)
		{
			for (int k = 0; k < resDiagramFinaly[i].size(); k++)
			{
				st = st + resDiagramFinaly[i][k];
			}

			st = st + "\n";
		}


		return st;
	}

};


int main()
{
	int N = 6;

	int* x = new int[N]{4,-2,3,0,1,-5};
	int* y = new int[N]{3,4,1,2,-3,3};

	VisualCorArr visualCorArr1(x, y, N);
	string st1 = visualCorArr1.result();
	cout << st1;


	delete[] x;
	delete[] y;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
