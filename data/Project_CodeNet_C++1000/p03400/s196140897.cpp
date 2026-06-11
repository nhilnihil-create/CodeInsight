/*https://atcoder.jp/contests/abc092/tasks/abc092_b*/
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
	int n, d, x, p = 0, a[100], count = 0;
	cin >> n >> d >> x;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1)
			p++;
		// cout << a[i] << " ";
		int b = 1, j = 1;
		while (b <= d)
		{
			if (b <= d)
				count++;
			b = a[i] * j + 1, j++;
			// cout << b << " ";

		}
		// cout << endl;

	}
	// for (int i = 0; i < v.size(); i++)
	// 	cout << v[i] << " ";
	// cout << endl;
	cout << count + x;
}