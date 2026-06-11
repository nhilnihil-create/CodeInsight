#include<bits/stdc++.h>
#define ll long long
#define ljc 998244353
using namespace std;
#define gc getchar
inline ll read(){
    register ll x=0,f=1;char ch=gc();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=gc();}
    while (isdigit(ch)){x=(x<<3)+(x<<1)+ch-'0';ch=gc();}
    return (f==1)?x:-x;
}
ll A,B,n,dp[2][5050],P[5050];
inline void chkmin(ll &a,const ll &b){if (a>b) a=b;}
signed main(){
	n=read(),A=read(),B=read();
	for (int i=1;i<=n;i++) P[i]=read();
	bool cur=0;
	memset(dp[cur],0x3f,sizeof dp[cur]);
	ll inf=dp[0][0];
	dp[0][0]=0;
	for (int i=1;i<=n;i++){
		cur^=1;
		memset(dp[cur],0x3f,sizeof dp[cur]);
		for (int j=0;j<=n;j++){
			chkmin(dp[cur][j],dp[cur^1][j]+A*(P[i]>j)+B*(P[i]<j));
			if (P[i]>j) chkmin(dp[cur][P[i]],dp[cur^1][j]);
		}
	}
	ll _=inf;
	for (int i=0;i<=n;i++) chkmin(_,dp[cur][i]);
	cout<<_;
	return 0;
}

