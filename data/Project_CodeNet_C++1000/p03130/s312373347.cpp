#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 1; i <= (n); i++)

signed main(void)
{
	int v[5];
	rep(i, 4) v[i] = 0;
	rep(i, 3)
	{
		int a, b;
		cin >> a >> b;
		v[a]++;
		v[b]++;
	}
	if (v[1] <= 2 && v[2] <= 2 && v[3] <= 2 && v[4] <= 2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
