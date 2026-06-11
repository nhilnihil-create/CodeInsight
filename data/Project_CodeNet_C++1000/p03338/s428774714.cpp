#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;
#define get(vv, times) for(int ii = 0; ii < times; ++ii) {int jj; cin >> jj; (vv).pb(jj);}

int n, both;
string s;
vector <int> v;

int32_t main() {
	cin >> n;
	cin >> s;
	rep(i, 1, n, 1) {
		string x = s.substr(0, i);
		string y = s.substr(i, n);
		set <char> a = set <char> (all(x));
		set <char> b = set <char> (all(y));
		both = 0;
		for (auto it:a) {
			if (b.find(it) != b.end()) ++both;
		}
		v.pb(both);
		cerr << x << ' ' << y << ' ' << both << '\n';
	}
	cout << *max_element(all(v));
}