#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	ll n, m,g,ni=0,mi=0;
	string s, t;
	bool ans = true;
	cin >> n >> m >> s >>t;
	//if (s[0] != t[0]) { cout << -1 << endl; return 0; }
	g = lcm(n, m);
	vector<ll>narr(n), marr(m);
	map<ll, int>mp;
	rep(i, n) {
		narr[i] = (g * i) / n;
		mp[narr[i]]++;
	}
	rep(i, m) {
		marr[i] = (g * i) / m;
		mp[marr[i]]++;
	}
	for (auto p : mp) {
		if (p.second == 1)continue;
		ni = lower_bound(all(narr), p.first) - narr.begin();
		mi = lower_bound(all(marr), p.first) - marr.begin();
		if (s[ni] != t[mi])ans = false;
	}
	if (ans) {
		cout << g << endl;
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}

