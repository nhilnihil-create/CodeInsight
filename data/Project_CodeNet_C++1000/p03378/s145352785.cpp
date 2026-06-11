/*https://atcoder.jp/contests/abc094/tasks/abc094_b*/
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
	int n, m, x, a[100], b[100], costA = 0, costB = 0;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++)
		b[i] = 0;
	for (int i = 0; i < m; i++)
		cin >> a[i], b[a[i] - 1] = 1;
	for (int i = x - 1; i < n; i++)
		costA += b[i];
	for (int i = x - 1; i >= 0; i--)
		costB += b[i];
	cout << min(costA, costB);
}