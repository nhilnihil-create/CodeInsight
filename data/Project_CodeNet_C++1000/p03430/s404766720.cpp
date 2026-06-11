#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int dp[305][305][305];
char s[maxn];

int main()
{
	scanf("%s",s+1); int K=read(),len=strlen(s+1);
	rep(i,1,len) dp[i][i][0]=1;
	rep(i,2,len) for(int l=1;l+i-1<=len;l++) for(int k=0;k<=K;k++)
	{
		int r=l+i-1;
		dp[l][r][k]=max(dp[l+1][r][k],dp[l][r-1][k]);
		if(s[l]==s[r]) dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k]+2);
		if(k) dp[l][r][k]=max(dp[l][r][k],dp[l+1][r-1][k-1]+2);
	}
	int ans=0;
	rep(i,0,K) ans=max(ans,dp[1][len][i]);
	cout<<ans<<endl;
	return 0;
}