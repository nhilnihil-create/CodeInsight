#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

signed main(void)
{
	int n, m, tmp, cnt;
	cin >> n >> m;
	vector<P> vec(m);
	rep(i, m) cin >> vec[i].second >> vec[i].first;
	sort(vec.begin(), vec.end());
	cnt = 0;
	tmp = -1;
	rep(i, m)
	{
		if (tmp <= vec[i].second)	
		{
			cnt++;
			tmp = vec[i].first;
		}
	}
	cout << cnt << endl;
	return 0;
}
