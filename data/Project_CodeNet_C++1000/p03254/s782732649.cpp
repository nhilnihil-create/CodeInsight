/*https://atcoder.jp/contests/agc027/tasks/agc027_a*/
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
	long long a[n], x;
	cin >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (x < a[i])
		{
			cout << count;
			return 0;
		}
		x -= a[i], count++;
	}
	if (x == 0)
		cout << count;
	else
		cout << n - 1;
}