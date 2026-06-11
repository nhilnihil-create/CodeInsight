#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define V vector
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define debug(x) cerr << #x << " is " << x << endl

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef V<int> vi;

const int INF = 1e9 + 7;

int n;

int trav(int cur, pi p) {
	if(p.F <= cur && cur <= p.S) return cur;
	if(cur < p.F) return p.F;
	return p.S;
}
ll go(multiset<pi> ls, multiset<pi> rs) {
	int cur = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		pi p;
		if(i & 1) p = *ls.rbegin();
		else {
			p = *rs.begin();
			swap(p.F, p.S);
		}
		ans += abs(trav(cur, p)-cur);
		cur = trav(cur, p);
		ls.erase(ls.lower_bound(p));
		swap(p.F, p.S);
		rs.erase(rs.lower_bound(p));
	}
	ans += abs(cur - 0);
	return ans;
}

ll go1(multiset<pi> ls, multiset<pi> rs) {
	int cur = 0;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		pi p;
		if((i & 1) == 0) p = *ls.rbegin();
		else {
			p = *rs.begin();
			swap(p.F, p.S);
		}
		ans += abs(trav(cur, p)-cur);
		cur = trav(cur, p);
		ls.erase(ls.lower_bound(p));
		swap(p.F, p.S);
		rs.erase(rs.lower_bound(p));
	}
	ans += abs(cur - 0);
	return ans;
}

signed main()
{
	IO_OP;
	
	cin >> n;
	multiset<pi> ls, rs;
	for(int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		ls.insert({l, r});
		rs.insert({r, l});
	}
	cout << max(go(ls, rs), go1(ls, rs)) << endl;

}



