#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}

const ll MOD = 1e9 + 7;
const ll MAXC = 2 * 1e5;
void mainsolve(){
	ll n;
	cin >> n;
	vector<ll> c(n);
	rep(i,n) cin >> c[i];
	vector<vector<ll>> memo(MAXC);
	rep(i,n){
		memo[--c[i]].push_back(i);
	}

	vector<ll> dp(n);
	dp[n-1] = 1;

	for(ll i = n-2; i >= 0; i--){
		dp[i] = dp[i+1] % MOD;
		if(c[i] == c[i+1]) continue;
		if(memo[c[i]].empty()) continue;
		auto loc = upper_bound(memo[c[i]].begin(), memo[c[i]].end(), i+1);
		if(loc != memo[c[i]].end() && *loc <= n-1) dp[i] = (dp[i] + dp[*loc]) % MOD;
	}
	cout << dp[0] << endl;
	return;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}