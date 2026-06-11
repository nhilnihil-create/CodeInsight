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
	int n, m, c, ans =0;
	cin >> n >> m >> c;
	vector<int> b(m);
	rep(i,m) cin >> b[i];
	rep(i,n){
		int sum = 0;
		rep(j,m){
			int a; cin >> a;
			sum += a*b[j];
		}
		if(sum+c > 0) ans++;
	}
	cout << ans << endl;
	return 0;
}