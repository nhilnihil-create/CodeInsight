#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define M(x) ((x)%mod)
ll bp(ll x, ll p) {
	ll res = 1;
	while(p) {
		if(p&1) res=(res*x)%mod;
		x=(x*x)%mod;
		p>>=1;
	}
	return res;
}
ll n, f[200100];
void setup() {
	f[1]=1;
	for(int i = 2; i <= 200000; i++)
		f[i] = M(f[i-1]+bp(i, mod-2));
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll ans = 0;
	ll n, t, c;
	setup();
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> t;
		c = M(f[i]+f[n-i+1]-1);
		ans = M(ans + M(c*t));
	}
	for(int i = 1; i <= n; i++)
		ans = M(ans*i);
	cout << ans;
}
