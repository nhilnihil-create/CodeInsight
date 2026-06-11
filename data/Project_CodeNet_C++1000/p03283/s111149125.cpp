#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n, m, q;
	int rui[501][501] = {};
	cin >> n >> m >> q;
	int l, r;
	for (int i = 0; i < m; ++i)
	{
		cin >> l >> r;
		++rui[l][r];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			rui[i][j] += rui[i][j-1];
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			rui[j][i] += rui[j-1][i];
		}
	}
	for (int Q = 0; Q < q; ++Q)
	{
		cin >> l >> r;
		int ma = max(l, r);
		int mi = min(l, r);
		cout << rui[ma][ma] - rui[ma][mi-1] - rui[mi-1][ma] + rui[mi-1][mi-1] << endl;
	}
	return 0;
}