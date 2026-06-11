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
const ll mod = 7 * 17 * (1 << 23) + 1;
const ll inf = 1e18 + 69;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	vi p;
	cin >> n;
	p.resize(n);
	for(int t, i = 0; i < n; i++) {
		cin >> t;
		--t;
		p[t] = i;
	}
	ll ans = 0, cur = 0;
	for(int r = -1, i = 0; i < n; i++) {
		if(p[i]<r) {
			cur = 0;
		}
		cur++;
		r = p[i];
		ans = max(ans, cur);
	}
	cout << n-ans;
}
