#include<bits/stdc++.h>
using namespace std;
#define REP(i,st,ed) for(register int i=st,i##end=ed;i<=i##end;++i)
#define DREP(i,st,ed) for(register int i=st,i##end=ed;i>=i##end;--i)
typedef long long ll;
inline int read(){
	int x;
	char c;
	int f=1;
	while((c=getchar())!='-' && (c<'0' || c>'9'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1)+(x<<3)+(c^'0');
	return x*f;
}
inline ll readll(){
	ll x;
	char c;
	ll f=1;
	while((c=getchar())!='-' && (c<'0' || c>'9'));
	if(c=='-') c=getchar(),f=-1;
	x=c^'0';
	while((c=getchar())>='0' && c<='9') x=(x<<1ll)+(x<<3ll)+(c^'0');
	return x*f;
}
const int maxn=300+10;
inline bool chkmax(int &x,int y){return (y>x)?(x=y,1):0;}
char s[maxn];
int dp[maxn][maxn][maxn];
int main(){
	scanf("%s",s+1);
	int m=read(),n=strlen(s+1);
	REP(i,1,n)
		DREP(j,n,i)
			REP(k,0,m){
				dp[i][j][k]=max(dp[i-1][j][k],dp[i][j+1][k]);
				if(s[i]==s[j]) chkmax(dp[i][j][k],dp[i-1][j+1][k]+1);
				else if(k>0) chkmax(dp[i][j][k],dp[i-1][j+1][k-1]+1);
			}
	int ans=0;
	REP(i,1,n){
		chkmax(ans,dp[i][i][m]*2-1);
		REP(j,i+1,n) chkmax(ans,dp[i][j][m]*2);
	}
	printf("%d\n",ans);
	return 0;
}
