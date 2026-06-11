#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3f
#define EPS (1e-10)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int dp[400][400][400];
signed main(){
	string s;int K;cin>>s>>K;
	rep(i,s.size()){
		for(int j=s.size()-1;j>i;j--){
			rep(k,K+1){
				if(s[i]==s[j]){
					dp[i+1][j-1][k]=max(dp[i+1][j-1][k],dp[i][j][k]+1);
				}
				{
					dp[i+1][j-1][k]=max(dp[i+1][j-1][k],dp[i][j][k]);
					dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
					dp[i][j-1][k]=max(dp[i][j-1][k],dp[i][j][k]);
					if(k<K){
						dp[i+1][j-1][k+1]=max(dp[i+1][j-1][k+1],dp[i][j][k]+1);
					}
				}
			}
		}
	}
	int Max=0,id=0;
	rep(i,s.size())rep(k,s.size())rep(j,K+1){
		if(Max<dp[i][k][j]){
			Max=dp[i][k][j];
			id=0;
		}
		if(Max==dp[i][k][j]){
			id=max(id,k-i+1);
		}
	}/*
	if(s.size()%2==1){
		cout<<Max*2+1<<endl;
	}
	else{
		if(Max*2!=s.size())cout<<Max*2+1<<endl;
		else cout<<Max*2<<endl;
	}
	//cout<<Max*2+2<<vendl;*/
	if(id)cout<<Max*2+1<<endl;
	else cout<<Max*2<<endl;
}