#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (ll)4e18;
const int inf = 1001001001;
const int mod = 1000000007;
typedef pair<ll, ll> PL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	vector<ll> a(x), b(y), c(z);
	rep(i, x) cin >> a[i];
	rep(i, y) cin >> b[i];
	rep(i, z) cin >> c[i];
	sort(rall(a));
	sort(rall(b));
	sort(rall(c));
	priority_queue<tuple<ll, int, int, int>> que;
	set<tuple<int, int, int>> done;
	que.emplace(a[0] + b[0] + c[0], 0, 0, 0);
	auto maybe_push = [&](int ai, int bi, int ci) -> void {
		auto tpl = make_tuple(ai, bi, ci);
		if (ai < x && bi < y && ci < z && !done.count(tpl)) {
			done.insert(tpl);
			que.emplace(a[ai] + b[bi] + c[ci], ai, bi, ci);
		}
	};
	int cnt = 0;
	while (que.size()) {
		ll sm = get<0>(que.top());
		int ai = get<1>(que.top());
		int bi = get<2>(que.top());
		int ci = get<3>(que.top());
		que.pop();
		cout << sm << endl;
		if (++cnt == k) break;
		maybe_push(ai + 1, bi, ci);
		maybe_push(ai, bi + 1, ci);
		maybe_push(ai, bi, ci + 1);
	}
	return 0;
}
