/*https://atcoder.jp/contests/abc088/tasks/abc088_b*/
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
	int n, a[100], sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)
			sum += a[i];
		else
			sum -= a[i];
	}
	cout << sum;
}