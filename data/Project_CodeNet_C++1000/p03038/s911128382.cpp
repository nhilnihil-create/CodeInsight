#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 1e9;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	map<ll, int> mp;
	rep (i, n) {
	  ll a;
	  cin >> a;
	  mp[a]++;
	}
	rep (i, m) {
	  int b;
	  ll c;
	  cin >> b >> c;
	  mp[c] += b;
	}
	int cnt = 0;
	ll res = 0;
	for (auto iter = mp.rbegin(); iter != mp.rend(); ++iter) {
	  if (cnt + iter->second > n) {
		res += iter->first * (n - cnt);
		break;
	  }
	  res += iter->first * iter->second;
	  cnt += iter->second;
	}
	cout << res << endl;
	
    return 0;
}
