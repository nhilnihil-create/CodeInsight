#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = (a); i < (b); ++i)
#define rrep(i,a,b) for(int i = (b); i --> (a);)
#define all(v) (v).begin(),(v).end()
#define trav(x,v) for(auto &x : v)
#define sz(v) int(v.size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pii;

const ll md = 1e9+7;

ll inv(ll a, ll b){
	return a!=1 ? b - inv(b%a,a)*b/a : 1LL;
}

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n);
	trav(x, a) cin >> x;

	vector<ll> dp(n);

	ll sum = 0;
	rep(i,1,n){
		dp[i] = (i + sum)*inv(i+1, md) % md;
		sum = (sum + dp[i])%md;
	}

	ll prod = 1;
	rep(i,1,n+1) prod = prod * i % md;

	ll ans = 0;
	rep(i,0,n){
		ll cur = dp[i] + dp[n-i-1] + 1;
		ans += cur * a[i] % md;
	}
	ans %= md;
	ans *= prod;
	ans %= md;
	if(ans < 0) ans += md;
	cout << ans << endl;
}