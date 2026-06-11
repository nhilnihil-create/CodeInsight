#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 605
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

int n,dp[maxn][maxn];
char s[maxn][maxn];

inline int sol(int x,int y)
{
	int tmp=min(x,y);
	rep(i,1,tmp-1) if(s[x][y-i]!=s[x-i][y]) return i;
	return tmp;
}

int main()
{
	n=read(); rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,n) s[i+n][j]=s[i][j],s[i][j+n]=s[i][j],s[i+n][j+n]=s[i][j];
	n<<=1; int ans=0;
	rep(i,1,n) rep(j,1,n) dp[i][j]=min(dp[i-1][j-1],sol(i,j)-1)+1;
	rep(i,1,n-1) rep(j,1,n-1) ans+=(dp[i][j]>=(n/2)); cout<<ans<<endl;
	return 0;
}