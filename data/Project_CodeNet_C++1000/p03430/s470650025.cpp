/* --- author: dxm --- */
#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long ll;
inline void Fail(){printf("0");exit(0);}

const int maxn=305;
int n,lim,ans;
char c[maxn];
string s;
int dp[maxn][maxn][maxn];

int main(){
	scanf("%s%d",c,&lim);
	s=c;n=s.size();
	REP(len,n)rep(i,n)rep(k,lim+1){
		int j=i+len-1;
		if(j>=n)break;
		if(s[i]==s[j])dp[i][j][k]=(len>=3?dp[i+1][j-1][k]:0)+(i==j?1:2);
		if(i<n-1)dp[i][j][k]=max(dp[i][j][k],dp[i+1][j][k]);
		if(j-1>0)dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]);
		if(s[i]!=s[j]&&k)
		dp[i][j][k]=max(dp[i][j][k],(len>=3?dp[i+1][j-1][k-1]:0)+2);
		ans=max(ans,dp[i][j][k]);
	}
	printf("%d",ans);
	return 0;
}

/*
Input:
-----------------
Output:
*/