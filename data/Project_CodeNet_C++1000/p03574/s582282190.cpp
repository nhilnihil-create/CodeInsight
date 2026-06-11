#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Max = 1e3 + 7;
char lst[Max][Max];
int ls[Max][Max];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf(" %c", &lst[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (lst[i][j] == '#')cout << "#";
			else
			{
				int sum = 0;
				if (lst[i + 1][j]=='#' && i + 1 <= n)sum++;
				if (lst[i - 1][j] == '#' && i - 1 >= 1)sum++;
				if (lst[i][j + 1] == '#' && j + 1 <= m)sum++;
				if (lst[i + 1][j+1] == '#' && i + 1 <= n&&j+1<=m)sum++;
				if (lst[i - 1][j-1] == '#' && i - 1 >= 1&&j-1>=1)sum++;
				if (lst[i][j - 1] == '#' && j - 1 >= 1)sum++;
				if (lst[i + 1][j - 1] == '#' && i + 1 <= n && j - 1 >= 1)sum++;
				if (lst[i - 1][j + 1] == '#' && i - 1 >= 1 && j + 1 <= m)sum++;
				cout << sum;
			}
		}
		cout << endl;
	}
}