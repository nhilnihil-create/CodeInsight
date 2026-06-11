#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=2e9+7;
const long double PI = acos(0);
// }}} End Header
int main() {
	ll R, G, B, n, ans=0;
	cin >> R >> G >> B >> n;
	for(ll r=0; r<=n; r++){
		for(ll g=0; g<=n; g++){
			if((n-R*r-G*g)%B == 0 && (n-R*r-G*g)/B >= 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
