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
	vector<vector<ll>> dp(s.sz,vector<ll>(4,0));
	if(s[0]=='A'){
		dp[0][0]=1;//カウントしない
		dp[0][1]=1;//する
	}
	else if(s[0]=='?'){
		dp[0][0]=3;
		dp[0][1]=1;
	}
	else dp[0][0]=1;

	rep1(i,s.sz-1){
		if(s[i]=='A'){
			dp[i][1]=dp[i-1][0];//する
			dp[i][3]=dp[i-1][3];
			dp[i][2]=dp[i-1][2];
			dp[i][1]+=dp[i-1][1];
			dp[i][0]=dp[i-1][0];

			dp[i][1]=mod(dp[i][1]);
		}else if(s[i]=='B'){
			dp[i][2]=dp[i-1][1];//する
			dp[i][3]=dp[i-1][3];
			dp[i][2]+=dp[i-1][2];
			dp[i][1]=dp[i-1][1];
			dp[i][0]=dp[i-1][0];

			dp[i][2]=mod(dp[i][2]);
		}else if(s[i]=='C'){
			dp[i][3]=dp[i-1][2];//する
			dp[i][3]+=dp[i-1][3];
			dp[i][2]=dp[i-1][2];
			dp[i][1]=dp[i-1][1];
			dp[i][0]=dp[i-1][0];

			dp[i][3]=mod(dp[i][3]);
		}
		else{
			dp[i][3]=dp[i-1][2];
			dp[i][2]=dp[i-1][1];
			dp[i][1]=dp[i-1][0];

			dp[i][3]+=mod(dp[i-1][3]*3);
			dp[i][2]+=mod(dp[i-1][2]*3);
			dp[i][1]+=mod(dp[i-1][1]*3);
			dp[i][0]+=mod(dp[i-1][0]*3);

			dp[i][3]=mod(dp[i][3]);
			dp[i][2]=mod(dp[i][2]);
			dp[i][1]=mod(dp[i][1]);
			dp[i][0]=mod(dp[i][0]);
		}
	}
	cout<<dp[s.sz-1][3];
}
