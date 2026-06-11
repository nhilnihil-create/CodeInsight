#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = (ll)1e9 + 7;
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)

signed main() {
	ll N;
	cin>>N;
	vector<ll> a(N,0);
	rep(i,N){
		cin>>a[i];
	}

	vector<vector<ll>> position(200001);
	rep(i,N){
		position[a[i]].push_back(i);
	}

	vector<ll> dp(N+1,0);
	dp[0]=1;
	rep(i,N){
		dp[i+1]=dp[i];

		auto it=lower_bound(position[a[i]].begin(), position[a[i]].end(), i);
		if(it!=position[a[i]].begin()){
			ll t=*it;
			it--;
			ll s=*it;
			if(t-s>1)dp[i+1]+=dp[s+1];
		}
		dp[i+1]%=MOD;
	}
	cout<<dp[N]<<endl;

	return 0;
}
