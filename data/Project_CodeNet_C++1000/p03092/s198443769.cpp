#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef pair<int,int>P;
typedef long long ll;

ll dp[6000][6000];
int p[6000];

int main(){
	int n,a,b;cin>>n>>a>>b;
	rep(i,n)scanf("%d",&p[i]);
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	rep(i,n)rep(j,n+1){
		if(dp[i][j]==INF)continue;
		if(j>p[i]){
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+b);
		}
		else{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a);
			dp[i+1][p[i]]=min(dp[i+1][p[i]],dp[i][j]);
		}
	}
	cout<<*min_element(dp[n],dp[n]+n+1)<<endl;
}