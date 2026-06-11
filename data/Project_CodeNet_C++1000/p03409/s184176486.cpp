#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;

signed main(void)
{
	int n, cnt;
	cin >> n;
	vector<bool> red(n, true);
	vector<P> r(n), b(n);

	rep(i, n) cin >> r[i].first >> r[i].second;
	rep(i, n) cin >> b[i].first >> b[i].second;
	sort(r.begin(), r.end());
	sort(b.begin(), b.end());
	cnt = 0;
	rep(i, n)
	{
		int j = 0;
		vector<P> tmp;
		while(r[j].first < b[i].first && j < n)
		{
			if (red[j] && r[j].second < b[i].second)
				tmp.push_back(P(r[j].second, j));
			j++;
		}
		if (tmp.size() != 0)
		{
			sort(tmp.rbegin(), tmp.rend());
			red[tmp[0].second] = false;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
