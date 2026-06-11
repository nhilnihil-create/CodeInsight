#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

ll f[100005], g[100005];

multiset<pair<ll, int>> rem, unused;
map<int, vector<ll>> entries;
map<int, bool> hold;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	
	int n, k; read(n, k);
	rep(i, 0, n) {
		int t, d; read(t, d);
		unused.insert({d, t});
		entries[t].push_back(d);
	}

	ll val = 0;
	rep(i, 0, k) {
		val += unused.rbegin()->first;
		if (!hold[unused.rbegin()->second]) {
			hold[unused.rbegin()->second] = true;
		} else {
			rem.insert(*unused.rbegin());
		}
		unused.erase(prev(unused.end()));
	}

	rep(i, 0, n + 1)
		f[i] = -0x3f3f3f3f3f3f3f3fll;

	f[hold.size()] = val;

	for (auto t : hold)
		for (auto e : entries[t.first])
			unused.erase({e, t.first});

	for (int i = hold.size() + 1; !unused.empty() && i <= k; i++) {
		val -= rem.begin()->first;
		rem.erase(rem.begin());
		int t = unused.rbegin()->second;
		val += unused.rbegin()->first;
		hold[t] = true;
		for (auto e : entries[t])
			unused.erase({e, t});
		f[i] = val;
	}

	ll ans = -0x3f3f3f3f3f3f3f3fll;

	for (ll i = 0; i <= n; i++)
		chmax(ans, f[i] + i * i);
	write(ans);
}
