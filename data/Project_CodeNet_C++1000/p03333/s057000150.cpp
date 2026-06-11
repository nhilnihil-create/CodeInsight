#include <bits/stdc++.h>
 

#define scanf abacaba
#define printf abacaba

 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
using namespace std;
 
 
/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
 
multiset<pair<int, int>> sl;
multiset<pair<int, int>> sr;
 
ll solve(int x) {
	ll ans = 0;
	ll cur = 0;
	int fl = 0;
	for (int i = x; !sl.empty() && fl < 2; ++i) {
		pair<int, int> p;
		if (i % 2 == 0) {
			p = *sl.rbegin();
			if (p.first <= cur && p.second >= cur) {
				fl += 1;
				continue;
			}
			sl.erase(sl.find(p));
			sr.erase(sr.find(make_pair(p.second, p.first)));
		}
		else {
			p = *sr.begin();
			swap(p.first, p.second);
			if (p.first <= cur && p.second >= cur) {
				fl += 1;
				continue;
			}
			sl.erase(sl.find(p));
			sr.erase(sr.find(make_pair(p.second, p.first)));
		}
		fl = 0;
		if (cur < p.first) {
			ans += abs(p.first - cur);
			cur = p.first;
		}
		else {
			ans += abs(p.second - cur);
			cur = p.second;
		}
	}
	ans += abs(cur);
	return ans;
}
 
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int l, r;
		cin >> l >> r;
		sl.insert(make_pair(l, r));
		sr.insert(make_pair(r, l));
	}
	auto tmpl = sl;
	auto tmpr = sr;
	ll ans = solve(0);
	sl = tmpl;
	sr = tmpr;
	ans = max(ans, solve(1));
	cout << ans << "\n";
	return 0;
}
