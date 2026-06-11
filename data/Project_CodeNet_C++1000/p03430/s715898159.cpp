#include <bits/stdc++.h>
using namespace std;

const int MaxN = 300;
const int MaxM = 300;

int n, m;
char s[MaxN + 2];

int f[MaxN + 1][MaxN + 1][MaxM + 1];

int main()
{
	cin >> s + 1 >> m;

	n = strlen(s + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= m; ++j)
			f[i][i][j] = 1;
	for (int i = 1; i < n; ++i)
	{
		f[i][i + 1][0] = 1 + (s[i] == s[i + 1]);
		for (int j = 1; j <= m; ++j)
			f[i][i + 1][j] = 2;
	}

	for (int k = 3; k <= n; ++k)
		for (int l = 1; l <= n - k + 1; ++l)
		{
			int r = l + k - 1;
			for (int i = 0; i <= m; ++i)
			{
				int j = i - (s[l] != s[r]);
				int w = j >= 0 ? f[l + 1][r - 1][j] + 2 : -1;
				f[l][r][i] = max(f[l + 1][r][i], f[l][r - 1][i]);
				f[l][r][i] = max(f[l][r][i], w);
			}
		}

	cout << f[1][n][m] << endl;

	return 0;
}