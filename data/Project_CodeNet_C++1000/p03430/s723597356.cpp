#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define all(v) v.begin(),v.end()
#define P pair<int,int>
#define len(s) (int)s.size()
#define pb push_back

template<class T> inline bool chmin(T &a, T b){
	if(a>b){a=b;return true;}
	return false;
}
template<class T> inline bool chmax(T &a, T b){
	if(a<b){a=b;return true;}
	return false;
}
constexpr int mod = 1e9+7;
constexpr int inf = 3e18;

string S;
int K;
int dp[305][305][305];
bool b[305][305][305];
int f(int l,int r,int k){
	if(b[l][r][k])return dp[l][r][k];
	b[l][r][k]=1;
	if(r-l==1)return dp[l][r][k]=1;
	if(r-l==2){
		if(S[l]==S[l+1])return dp[l][r][k]=2;
		return dp[l][r][k]=k?2:1;
	}
	dp[l][r][k]=1;
	chmax(dp[l][r][k],f(l,r-1,k));
	chmax(dp[l][r][k],f(l+1,r,k));
	if(S[l]==S[r-1])chmax(dp[l][r][k],f(l+1,r-1,k)+2);
	else if(k)chmax(dp[l][r][k],f(l+1,r-1,k-1)+2);
	return dp[l][r][k];
}
signed main(){
	cin>>S>>K;
	cout<<f(0,len(S),K)<<endl;
}
