#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;i++)
#define foi(i,a,n) for(long long int i=a;i<n;i++)
#define el "\n"

const int INF = 2e9+5;
const int MAX = 1e5+5;
const int mod = 1e9+7;
using ll = long long int;

void solve(){
	int n,m;cin>>n>>m;
  	vector<vector<int>> gr(n,vector<int>(m,1)),dp(n,vector<int>(m,0));
  	dp[0][0]=1;
  	rep(i,n)rep(j,m){
    	char temp;cin>>temp;
      	if(temp=='#')gr[i][j]=0;
    }
  	rep(i,n)rep(j,m){
    	if(gr[i][j]){
        	if(i-1>=0)dp[i][j]+=dp[i-1][j]%mod;
          	if(j-1>=0)dp[i][j]+=dp[i][j-1]%mod;
          	dp[i][j]%=mod;
        }
    }
  	cout<<dp[n-1][m-1]<<el;
}

int main(){
  solve();
  return 0;
}