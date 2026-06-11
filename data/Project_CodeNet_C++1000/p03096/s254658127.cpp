#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i = (m); i <= (n); i++)
#define rrep(i,m,n) for(ll i = (m); i >= (n); i--)
#define print(x) cout << (x) << endl;
#define printa(x,m,n) for(ll i = (m); i <= n; i++){cout << (x[i]) << " ";} cout<<endl;

ll n, c[200008], dp[200008], cnt[200008];

int main(){
	cin.tie(0); ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, 1, n){
		cin >> c[i];
	}
	
	cnt[c[1]] = 1;
	memset(dp, 0, sizeof(dp));
	rep(i, 1, n){
		if(c[i] != c[i+1]){
			dp[i] += cnt[c[i]];
			dp[i] %= MOD;
			cnt[c[i+1]] += dp[i];
			cnt[c[i+1]] += MOD;
		}
	}
	
	print(dp[n])
	return 0;
}