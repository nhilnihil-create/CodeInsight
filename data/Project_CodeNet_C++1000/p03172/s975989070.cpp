#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e9
int MOD = 1e9+7;
ll a[103];
ll n,K;
ll dp[103][(ll)(1e5+1)];
//doing it forward dp style and with a optimisation
int main(){
	cin>>n>>K;
	memset(dp,0,sizeof dp);
	for(ll i=0;i<n;i++) cin>>a[i];
	dp[0][0]=1; 
	for(int i=0;i<n;i++){
		vector<ll> to_add(K+1);
		for(ll used=0;used<=K;used++){
			ll L = used;
			ll R = used + min(K-used,a[i]);
			to_add[L] += dp[i][used];
			if(R+1<=K) to_add[R+1] += (-dp[i][used]);
			// for(int here = 0;used+here<=K&&here<=a[i];here++){
			// 	dp[i+1][used+here]+=dp[i][used];
			// }
		}
		ll pref_sum=0;
		for(int j=0;j<=K;j++){
			pref_sum += to_add[j];
			dp[i+1][j] = pref_sum%MOD;
		}
	}
	cout<<(dp[n][K]%MOD)<<endl;
	return 0;
}