#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;

signed main(void)
{
	int n, h, m;
	cin >> n >> h >> m;
	cout << (n - h + 1) * (n - m + 1) << endl;
	return 0;
}
