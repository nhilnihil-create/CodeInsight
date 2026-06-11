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

int main() {
	vector<int> t(3);
	int ans = 0;
	rep(i,3) cin >> t[i];
	sort(all(t));
	if((t[1]-t[0])%2 != 0){
		t[2]++;
		t[0]++;
		ans++;
	}
	ans+=(t[2]-t[1]);
	ans+=(t[1]-t[0])/2;
	cout << ans << endl;
	return 0;
}