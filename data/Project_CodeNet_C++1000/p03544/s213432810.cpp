/*https://atcoder.jp/contests/abc079/tasks/abc079_b*/
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
	int n;
	cin >> n;
	long long l[87];
	l[0] = 2, l[1] = 1;
	for (int i = 2; i <= n; i++)
		l[i] = l[i - 2] + l[i - 1];
	cout << l[n];
}
