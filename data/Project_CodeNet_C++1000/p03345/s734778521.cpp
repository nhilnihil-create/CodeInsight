#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int a, b, c;
	long long k;
	cin >> a >> b >> c >> k;
	if (k % 2 == 0)
		cout << a - b << endl;
	else
		cout << b - a << endl;
	return 0;
}
