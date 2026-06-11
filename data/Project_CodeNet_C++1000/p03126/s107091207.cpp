/*https://atcoder.jp/contests/abc118/tasks/abc118_b*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k, a[30][30], b[30];
	cin >> n >> m;
	for (int i = 0; i < m + 1; i++)
		b[i] = 0;
	int l = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			cin >> a[l][j];
			b[a[l][j]]++;
		}
		l++;
	}
	int count = 0;
	for (int i = 1; i < m + 1; i++)
	{

		if (b[i] == n)
			count++;
	}
	cout << count;

}