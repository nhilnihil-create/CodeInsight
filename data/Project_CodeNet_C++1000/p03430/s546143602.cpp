#include <bits/stdc++.h>
#define all(vec) vec.begin(),vec.end()
#define mp make_pair
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
const ll INF=1LL<<30;
const ll LINF=1LL<<60;
const double eps=1e-5;
const ll MOD=1000000007LL;
template<typename T>void chmin(T &a,T b){a=min(a,b);};
template<typename T>void chmax(T &a,T b){a=max(a,b);};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int dp[310][310][310];
int main(){
	string s;cin>>s;
	int K;cin>>K;
	int n=s.length();
	for(int i=0;i<n;i++){
		dp[i][i+1][0]=1;
	}
	for(int l=2;l<=n;l++){
		for(int i=0;i<=n-l;i++){
			int j=i+l;
			for(int k=0;k<=K;k++){
				chmax(dp[i][j][k],dp[i+1][j][k]);
				chmax(dp[i][j][k],dp[i][j-1][k]);
				if(s[i]==s[j-1]){
					chmax(dp[i][j][k],dp[i+1][j-1][k]+2);
				}else{
					if(k)chmax(dp[i][j][k],dp[i+1][j-1][k-1]+2);
				}
			}
		}
	}
	int ans=0;
	for(int k=0;k<=K;k++){
		chmax(ans,dp[0][n][k]);
	}
	cout<<ans<<endl;
    return 0;
}
