/*https://atcoder.jp/contests/abc087/tasks/abc087_b*/
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
	int a, b, c, x, count = 0;
	cin >> a >> b >> c >> x;
	if (x % 50 != 0)
	{
		cout << "0";
		return 0;
	}
	for (int i = 0; i <= a; i++)
	{
		for (int j = 0; j <= b; j++)
		{
			for (int k = 0; k <= c; k++)
			{
				int temp = i * 500 + j * 100 + k * 50;
				// cout << temp << " " << i << " " << j << " " << k << endl;
				if (temp == x)
					count++;
			}
		}
	}
	cout << count;
}