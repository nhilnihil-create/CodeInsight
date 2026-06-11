#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;

signed main(void)
{
	int h, w, d, l, r, q;
	cin >> h >> w >> d;
	P memo[h * w];
	vector<int> dist(h * w, 0);

	rep(i, h) rep(j, w)
	{
		int a;
		cin >> a;
		a--;
		memo[a] = P(i, j);
	}
	rep(i, h * w - d)
	{
		dist[i + d] = dist[i] + abs(memo[i].first - memo[i + d].first) +\
					  abs(memo[i].second - memo[i + d].second);
	}
	cin >> q;
	rep(i, q)
	{
		cin >> l >> r;
		--l; --r;
		cout << dist[r] - dist[l] << endl;
	}
	return 0;
}
