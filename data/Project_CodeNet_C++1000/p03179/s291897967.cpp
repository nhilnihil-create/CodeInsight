/* * * * * * * * * * * **
*                      *
*	   saurabh8522	   *
*	  I will handle	   *
*		   IT.		   *
*                      *
* * * * * * * * * * * **/
#include<bits/stdc++.h>
#define mp(a,b) make_pair(a,b)
#define pb push_back
#define FastRead ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define ld long double
#define zero(a) memset((a),0,sizeof((a)))
#define one(a) memset((a),1,sizeof((a)))
#define minus(a) memset((a),-1,sizeof((a)))
#define all(g) g.begin(),g.end()
#define ppb pop_back
using namespace std;
typedef long long int ll;
#define MOD 1000000007
ll extgcd(ll a,ll b,ll& x,ll& y){if(b==0){x=1;y=0;return a;}else{int g=extgcd(b,a%b,y,x);y-=a/b*x;return g;}}
ll modpow(ll a,ll b) {ll res=1;a%=MOD;for(;b;b>>=1){if(b&1)res=res*a%MOD;a=a*a%MOD;}return res;}
ll numdigit(ll n){return floor(log10(n)) + 1;}
bool isPowerTwo (ll x) { return x && (!(x&(x-1))); } 
int  main(){
	FastRead;
	ll t=1;
	// cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s;cin>>s;
		ll dp[n+5][n+5];
		zero(dp);
		dp[1][1]=1;
		for(int i=2;i<=n;i++){
			vector<ll>sum(n,0);
			// cout<<"i="<<i<<" "<<endl;
			for(int j=1;j<=i-1;j++){
				sum[j]=(sum[j-1]+dp[i-1][j])%MOD;
				// cout<<"j="<<j<<"sum="<<sum[j]<<endl;
			}
			for(int j=1;j<=i;j++){
				int l,r;
				if(s[i-2]=='<'){
					l=1,r=j-1;
				}
				else{
					l=j,r=i-1;
				}
				// cout<<"j="<<j<<"l="<<l<<"r="<<r<<endl;
				if(l<=r){
					dp[i][j]=(dp[i][j]+(sum[r]-sum[l-1]+MOD)%MOD)%MOD;
				}
			}
		}
		ll res=0;
		for(int i=1;i<=n;i++){
			res=(res+dp[n][i])%MOD;
			// cout<<i<<" "<<dp[n][i]<<endl;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				// cout<<dp[i][j]<<" ";
			}
			// cout<<endl;
		}
		cout<<res<<endl;
	}
}