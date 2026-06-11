#include <bits/stdc++.h>
#define IOS   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define mp    make_pair
#define pb    push_back
#define F     first
#define pi 	  3.14159265358979323846
#define S     second
#define ll    long long
#define ld    long double
#define sz(s) (ll)s.size() 
#define vl    vector < ll >
#define pll   pair < ll, ll >
#define ml    map < ll, ll >
#define mod   1000000007
#define qe	  998244353
#define MAXN  1e5+5
#define mx    10000005
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define inv(i,a,b)  for(i=a;i>=b;i--)
#define all(a)  (a).begin(),(a).end()
using namespace std;
ll set_bit(ll n){
	ll ans=0;
	while(n){
		if(n&1)ans++;
		n>>=1;
	}
	return ans;
}
ll dp[1<<21]={0};
int main(){
//	#ifndef ONLINE_JUDGE
//    if (fopen("input.txt", "r"))
//    {
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    }
//	#endif
	IOS;
	ll t,n,l,l1;
	ll i,j,m,mn,q,d,x,y,sum=0,r,p,k,c;
	string s,s1;
	cin>>n;
	ll a[n][n];
	rep(i,0,n)rep(j,0,n)cin>>a[i][j];
	
	rep(i,0,1<<n){
		k=set_bit(i);		
		rep(j,0,n){
			if(a[k][j] && !(i&(1<<j))){
				if(k==0)dp[i|1<<j]=1;
				else dp[i|1<<j]+=dp[i];
				dp[i|1<<j]=dp[i|1<<j]%mod;
			}
			
		}
	}
//	rep(i,0,1<<n)cout<<dp[i]<<" ";
	cout<<dp[(1<<n)-1];
}