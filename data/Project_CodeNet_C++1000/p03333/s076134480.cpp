//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
const ll inf = 1e18 + 69;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n;
vector<pair<int, int>> seg;
ll solve(int X) { //go left first
	ll ans = 0;
	set<pair<int, int>> l, r;
	for (int i = 0; i < n; i++)
		l.insert( { seg[i].first, i }), r.insert( { seg[i].second, i });

	ll cur = 0;
	for(int i = 0; i < n; i++) {
		if(X^(i&1)) {
			auto t = *r.begin();
			ans += max(cur-t.first, 0ll);
			cur = min((ll)t.first, cur);
			r.erase(t);
			l.erase({seg[t.second].first, t.second});
		} else {
			auto t = *l.rbegin();
			ans += max(t.first-cur, 0ll);
			cur = max((ll)t.first, cur);
			l.erase(t);
			r.erase({seg[t.second].second, t.second});
		}
	}
	return ans+abs(cur);
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	seg.resize(n);
	for (auto &i : seg)
		cin >> i.first >> i.second;
	cout << max(solve(0), solve(1));
}
