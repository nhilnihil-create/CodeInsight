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
	int n;
	double ans=0;
	cin >> n;
	rep(i,n){
		double x; string s;
		cin >> x >> s;
		if(s == "JPY") ans+=x;
		else ans+=380000*x;
	}
	printf("%.15f", ans);
	return 0;
}