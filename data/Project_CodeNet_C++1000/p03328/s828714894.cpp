#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int a, b, n;
	cin >> a >> b;
	n = b - a;
	cout << n * (n - 1) / 2 - a << endl;
	return 0;
}
