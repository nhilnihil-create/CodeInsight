#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

ll f(ll t){
	ll cnt = 0;
	while(t%2 == 0){
		t/=2;
		cnt++;
	}
	return cnt;
}
int main() {
	ll n, ans = 0;
	cin >> n;
	rep(i,n){
		ll k; cin >> k;
		if(k%2 == 0) ans+=f(k);
	}
	cout << ans << endl;
	return 0;
}