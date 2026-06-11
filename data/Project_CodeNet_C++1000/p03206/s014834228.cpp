#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int d;
	cin >> d;
	d = 25 - d;
	cout << "Christmas";
	rep(i, d)
	{
		cout << " Eve";
	}
	cout << endl;
	return 0;
}
