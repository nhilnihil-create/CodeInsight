#include<bits/stdc++.h>
using namespace std;
const int N=310;
char s[N]; int k,dp[N][N][N];
inline void cmax(int &x,int y){x=max(x,y);}
inline int dfs(int a,int b,int c){
	if(a==b)return 1; if(a>b)return 0;
	if(dp[a][b][c])return dp[a][b][c];
	if(s[a]==s[b])cmax(dp[a][b][c],dfs(a+1,b-1,c)+2);
	else if(c)cmax(dp[a][b][c],dfs(a+1,b-1,c-1)+2);
	cmax(dp[a][b][c],dfs(a+1,b,c));
	cmax(dp[a][b][c],dfs(a,b-1,c));
	return dp[a][b][c];
}
int main(){
	scanf("%s%d",s+1,&k); int len=strlen(s+1);
	for(int i=1; i<=len; ++i)dp[i][i][0]=1;
	int ans=0;
	for(int i=1; i<=len; ++i)
		for(int j=i; j<=len; ++j)
			cmax(ans,dfs(i,j,k));
	printf("%d",ans);
	return 0;
}