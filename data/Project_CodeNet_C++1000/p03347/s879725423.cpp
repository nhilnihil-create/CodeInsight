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
vi v;
ll solve() {
	if(v[0]) cout <<-1, exit(0);
	ll ans = 0;
	for(int i = 1; i < v.size(); i++) {
		if(v[i]-1==v[i-1])ans++;
		else if(v[i]<=v[i-1]) ans += v[i];
		else cout <<-1, exit(0);
	}
	return ans;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, t;
	cin >> n;
	ll ans = 0;
	while(n--) {
		cin >> t;
		v.pb(t);
	}
	cout << solve();
}
