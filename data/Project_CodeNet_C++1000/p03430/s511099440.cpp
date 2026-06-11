#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;


string str[2];
int n,k;
int dp[305][305][305];
int dp2[305][305][305];

int solve(int f,int t,int r){
	//printf("%d %d %d\n",f,t,r);
	if(r<=-1)return -514514;
	if(f>=t)return 0;
	if(dp2[f][t][r]!=-1)return dp2[f][t][r];
	int maxi=0;
	if(str[0][f]==str[0][t-1]){
		if(f+1==t){
			maxi=max(maxi,1);
		}else{
			maxi=max(maxi,solve(f+1,t-1,r)+2);
		}
	}else{
		maxi=max(maxi,solve(f+1,t-1,r-1)+2);
	}
	maxi=max(maxi,solve(f+1,t,r));
	maxi=max(maxi,solve(f,t-1,r));
	//printf("%d %d %d %d\n",f,t,r,maxi);
	return (dp2[f][t][r]=maxi);
}

int main(void){
	memset(dp2,-1,sizeof(dp2));
	cin >> str[0];
	scanf("%d",&k);
	n=str[0].size();
	for(int i=0;i<n;i++){
		str[1]+=str[0][i];
	}
	reverse(str[1].begin(),str[1].end());
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	int ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int a=0;a<=k;a++){
				if(dp[i][j][a]>=0){
					ans=max(ans,solve(i,n-j,k-a)+dp[i][j][a]*2);
					dp[i+1][j][a]=max(dp[i+1][j][a],dp[i][j][a]);
					dp[i][j+1][a]=max(dp[i][j+1][a],dp[i][j][a]);
					if(i<n && j<n){
						if(str[0][i]==str[1][j]){
							dp[i+1][j+1][a]=max(dp[i+1][j+1][a],dp[i][j][a]+1);
						}else if(a<k){
							dp[i+1][j+1][a+1]=max(dp[i+1][j+1][a+1],dp[i][j][a]+1);
						}
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}