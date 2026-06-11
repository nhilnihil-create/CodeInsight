/*https://atcoder.jp/contests/agc024/tasks/agc024_a*/
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
	long long a, b, c, d, e, f, k;
	cin >> a >> b >> c >> k;
	if (a == b && a == c)
	{
		cout << "0";
		return 0;
	}
	if (k % 2 == 0)
		cout <<a - b;
	else
		cout <<b-a;

}