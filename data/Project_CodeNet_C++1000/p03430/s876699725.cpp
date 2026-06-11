#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int INF=1e9;
const long double eps=1e-9;
const int maxn=3e2+10;
int dp[maxn][maxn][maxn];
char str[maxn];
inline int read(){
	int x=0,flag=1;
	char ch=getchar();
	while(!isdigit(ch) && ch!='-')ch=getchar();
	if(ch=='-')flag=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return x*flag;
}
inline void chkmax(int &x,int y){
	x=x>y?x:y;
}
int main(){
	int i,j,k,m,n;
	scanf("%s",str+1);
	n=strlen(str+1);m=read();
	dp[0][n+1][0]=0;
	for(i=1;i<=n;i++)
		for(j=n;j>=i;j--)
			for(k=0;k<=m;k++){
				if(str[i]==str[j])chkmax(dp[i][j][k],dp[i-1][j+1][k]+1);
				else if(k)chkmax(dp[i][j][k],dp[i-1][j+1][k-1]+1);
				chkmax(dp[i][j][k],dp[i][j+1][k]);chkmax(dp[i][j][k],dp[i-1][j][k]);
			}
	int ans=0;
	for(i=1;i<=n;i++)
		for(j=0;j<=m;j++)
			ans=max(ans,dp[i][i][j]*2-1);
	for(i=1;i<=n;i++)
		for(j=i+1;j<=n;j++)
			ans=max(ans,dp[i][j][m]*2);
	printf("%d\n",ans);
	return 0;
}
