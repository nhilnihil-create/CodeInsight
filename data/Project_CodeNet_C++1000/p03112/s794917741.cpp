#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> P;
constexpr auto INF = INT_MAX/2;
constexpr auto LINF = 5000000000000000;
constexpr auto MOD = 1000000007;

int main() {

	int a, b, q;
	cin >> a >> b >> q;
	vector<ll> s(a), t(b), x(q);
	rep(i, a)cin >> s[i];
	rep(i, b)cin >> t[i];
	rep(i, q)cin >> x[i];

	rep(i, q) {

		ll xx = x[i];
		int ss, tt;
		ss = lower_bound(all(s), xx)-s.begin();
		tt = lower_bound(all(t), xx)-t.begin();

		ll rs, rt, ls, lt;
		if (ss == 0)ls = LINF;
		else ls = xx - s[ss - 1];
		if (tt == 0)lt = LINF;
		else lt = xx - t[tt - 1];
		if (ss == a)rs = LINF;
		else rs = s[ss] - xx;
		if (tt == b)rt = LINF;
		else rt = t[tt] - xx;

		vector<ll> dist;
		dist.push_back(max(ls, lt));
		dist.push_back(max(rs, rt));
		dist.push_back(rs+lt+min(rs,lt));
		dist.push_back(ls+rt+min(ls,rt));
		
		ll ans = LINF;
		rep(j, dist.size())ans = min(ans, dist[j]);
		cout << ans << endl;
	}
}