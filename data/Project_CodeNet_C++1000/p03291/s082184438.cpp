#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> TUP;
#define a first
#define b second
#define sz size()
#define pb(x) push_back(x) 
#define bg begin()
#define ed end()
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep1(i,n) for(ll i=1;i<=n;i++)
#define mp(x,y) make_pair(x,y)
const ll MOD=1000000007;

ll maxx(ll x,ll y,ll z){
	return max(max(x,y),z);
}
ll minn(ll x,ll y,ll z){
	return min(min(x,y),z);
}
ll gcd(ll x,ll y){
	if(x%y==0) return y;
    else return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x*(y/gcd(x,y));
}

ll mod(ll x){
	return x%MOD;
}

//a,b x
int main(){
	string s; cin>>s;
	vector<vector<ll>> dp(s.sz+1,vector<ll>(4,0));
	dp[s.sz][3]=1;
	rep(i,3) dp[s.sz][i]=0;
	
	for(int i=s.sz-1;i>=0;i--){
		if(s[i]=='?') dp[i][3]=(3*dp[i+1][3])%MOD;
		else dp[i][3]=dp[i+1][3];

		rep(j,3){
			ll m1=1,m2=0;
			if(s[i]=='?') m1=3;
			if(s[i]=='?' || s[i]-'A'==j) m2=1;
			dp[i][j]=((m1*dp[i+1][j])%MOD+m2*dp[i+1][j+1])%MOD;
		}
	}
	cout<<dp[0][0];
}