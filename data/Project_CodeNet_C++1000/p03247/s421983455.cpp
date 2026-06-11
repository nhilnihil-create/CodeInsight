#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int n;
int X[1001], Y[1001];
int M;
int OutputArray[1000];
char OutputString[1000];


int main()
{
	int i, j;
	int u, v;

	cin >> n;

	for (i = 0; i < n; i++)
	{
		cin >> X[i] >> Y[i];
	}

	int mod2Result = (X[0] + Y[0]) % 2;
	//cout << mod2Result;
	for (i = 1; i < n; i++)
	{
		//cout << (X[i] + Y[i]) % 2;
		if (abs((X[i] + Y[i]) % 2) != abs(mod2Result))
		{
			cout << "-1\n";
			return 0;
		}
	}

	M = 31;
	for (i = 30; i >= 0; i--)
	{
		OutputArray[30 - i] = (1 << i);
	}
	if (mod2Result == 0)
	{
		M++;
		OutputArray[31] = 1;
	}

	cout << M << "\n";
	for (i = 0; i < M; i++)
	{
		cout << OutputArray[i] << " ";
	}
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		u = X[i] + Y[i];
		v = X[i] - Y[i];

		for (j = 0; j < M; j++)
		{
			//cout << u << " " << v << "\n";
			if (u >= 0)
			{
				if (v >= 0)
				{
					OutputString[j] = 'R';
					u -= OutputArray[j];
					v -= OutputArray[j];
				}
				else
				{
					OutputString[j] = 'U';
					u -= OutputArray[j];
					v += OutputArray[j];
				}
			}
			else
			{
				if (v >= 0)
				{
					OutputString[j] = 'D';
					u += OutputArray[j];
					v -= OutputArray[j];
				}
				else
				{
					OutputString[j] = 'L';
					u += OutputArray[j];
					v += OutputArray[j];
				}
			}
		}
		OutputString[M] = 0;
		cout << OutputString << "\n";
	}
	

	return 0;
}