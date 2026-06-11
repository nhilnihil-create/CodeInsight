#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, m, X, Y;
	cin >> n >> m >> X >> Y;
	vector<int> x(n), y(m);
	bool ok;
	
	rep(i, n) cin >> x[i];
	rep(i, m) cin >> y[i];
	sort(x.rbegin(), x.rend());
	sort(y.begin(), y.end());
	ok = false;
	for(int i = X + 1; i < Y + 1; i++)
	{
		if (x[0] < i && i <= y[0])
			ok = true; 
	}
	if (!ok)
		cout << "War" << endl;
	else
		cout << "No War" << endl;
	return 0;
}
