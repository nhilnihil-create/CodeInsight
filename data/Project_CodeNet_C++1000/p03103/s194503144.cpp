#include <bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=(l);i<(r);i++)
#define pb push_back
#define fi first
#define se second

using ll = long long;
using G = vector<vector<int>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;

ll GCD(ll x, ll y){
	return y ? GCD(y, x%y) : x;	
}
ll LCM(ll x, ll y){
	return x/GCD(x, y)*y;
}

int main() {
	 ll n, m; cin >> n >> m;
	 ll a[100005], b[100005];
	 vector<pll> v;
	 rep(i, 0, n){
		 cin >> a[i] >> b[i];
		 v.pb({a[i], b[i]});
	 }
	 sort(v.begin(), v.end());
	 ll ans = 0;
	 ll cnt = 0;
	 for(auto p: v){
		 ans += p.fi*min(p.se, m-cnt);
		 cnt += min(p.se, m-cnt);
		 if(cnt==m) break;
	 }
	 cout << ans << endl;
	return 0;
}