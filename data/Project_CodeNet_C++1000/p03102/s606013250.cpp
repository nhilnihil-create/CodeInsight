/*https://atcoder.jp/contests/abc121/tasks/abc121_b*/
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
	int n, m, c, a[100][100], b[100], sum = 0;
	cin >> n >> m >> c;
	for (int i = 0; i < m; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	// for (int i = 0; i < n; i++)
	// {
	// 	for (int j = 0; j < m; j++)
	// 		cout << a[i][j] << " ";
	// 	cout << endl;
	// }

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		sum = c;
		for (int j = 0; j < m; j++)
			sum += a[i][j] * b[j];
		// cout << sum << endl;
		if (sum > 0)
			count++;
	}
	cout << count;
}