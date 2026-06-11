#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define pf push_front
#define pii pair <int, int>
#define all(vv) (vv).begin(), (vv).end()
#define rep(ii, jj, ll, ss) for(int ii = jj; ii < ll; ii += ss)
#define time cerr << '\n' << (double)clock()/CLOCKS_PER_SEC << '\n'; return 0;

string s;
vector <char> v;

int32_t main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> s;
	v.pb(s[0]);
	rep(i, 1, (int)s.length(), 1) {	
		if (s[i] == '1' && v.size() && v.back() == '0') {
			v.pop_back();
			continue;
		}
		else if (s[i] == '0' && v.size() && v.back() == '1') {
			v.pop_back();
			continue;
		}
		v.pb(s[i]);
	}
	cout << (int)s.length() - (int)v.size();
	time
}