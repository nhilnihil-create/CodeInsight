/*https://atcoder.jp/contests/abc081/tasks/abc081_b*/
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
	int n, count = 0;
	cin >> n;
	long long a[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2 != 0)
		{
			cout << count;
			return 0;
		}
	}
	int flag = 0;
	do {
		for (int i = 0; i < n; i++)
		{
			if (a[i] % 2 == 0)
				a[i] /= 2;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			count++;

	} while (flag == 0);
	cout << count;
}