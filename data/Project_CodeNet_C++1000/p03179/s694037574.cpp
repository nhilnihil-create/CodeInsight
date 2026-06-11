#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18
ll MOD = 1e9+7;
ll a[403];
ll n,K;
ll dp[3003][3003];
//T 
//dp[i][j] - number of ways for making prefix i with last number as j
int main(){
	int n;cin>>n;
	string s;cin>>s;
	dp[1][1] = 1;
	for(int len=2;len<=n;len++){
		vector<ll> pref(len+1);
		for(int i=2;i<=len;i++){
			pref[i] = pref[i-1] + dp[len-1][i-1];
			pref[i]%= MOD;
		}
		for(int b=1;b<=len;b++){//the number i am considering on the len psn
			int L,R;
			if(s[len-2]=='<') L = 1,R = b-1;
			else L = b,R = len-1;
			// from L to R -- I have to add in dp[len][b] -- direct prefix_sum application
			dp[len][b] = (pref[R+1] - pref[L] + MOD);
			dp[len][b] %= MOD;
			// for(int a=1;a<=(len-1);a++){//num on len-1 posn
			// 	int real_a = (a>=b)?a+1:a;
			// 	assert(real_a!=b);
			// 	if((real_a<b) != (s[len-2]=='<')) continue;
			// 	// cout<<"?";
			// 	dp[len][b] += dp[len-1][a];
			// 	dp[len][b] %= MOD;
			// }
			// cout<<len<<" "<<b<<" "<<dp[len][b]<<endl;
		} 
	}
	ll ans=0;
	for(int a=1;a<=n;a++) {ans+=dp[n][a];ans%= MOD;}
	cout<<ans<<endl;
}