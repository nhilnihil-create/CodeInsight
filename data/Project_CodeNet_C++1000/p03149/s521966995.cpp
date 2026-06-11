#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	vector<int> n(4);
	rep(i, 4) cin >> n[i];
	sort(n.begin(), n.end());
	if (n[0] == 1 && n[1] == 4 && n[2] == 7 && n[3] == 9)
	{
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
