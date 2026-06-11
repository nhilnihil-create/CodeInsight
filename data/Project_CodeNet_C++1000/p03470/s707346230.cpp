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

int n;
set <int> v;

int32_t main() {
	cin >> n;
	rep(i, 0, n, 1) {
		int x; cin >> x;
		v.insert(x);
	}
	cout << v.size();
}