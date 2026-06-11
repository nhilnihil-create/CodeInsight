/*https://atcoder.jp/contests/abc127/tasks/abc127_c*/
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
	int n, m;
	cin >> n >> m;
	int l[m], r[m], lmax = 0, rmin = 0;
	for (int i = 0; i < m; i++)
		cin >> l[i] >> r[i];
	sort(l, l + m);
	sort(r, r + m);
	lmax = l[m - 1], rmin = r[0];
	cout << max(0, rmin - lmax + 1);
}