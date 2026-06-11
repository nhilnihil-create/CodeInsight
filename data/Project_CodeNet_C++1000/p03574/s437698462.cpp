#include<iostream>
using namespace std;
	char a[55][55];
int main()
{
	int n, m; cin >> n >> m; 
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == '#')cout << "#";
			else
			{
				int sum = 0;
				if (a[i - 1][j - 1] == '#')sum++;
				if (a[i][j - 1] == '#')sum++;
				if (a[i - 1][j] == '#')sum++;
				if (a[i][j + 1] == '#')sum++;
				if (a[i - 1][j + 1] == '#')sum++;
				if (a[i + 1][j] == '#')sum++;
				if (a[i + 1][j + 1] == '#')sum++;
				if (a[i + 1][j - 1] == '#')sum++;
				cout << sum;
			}
		}
		cout << endl;
	}
}