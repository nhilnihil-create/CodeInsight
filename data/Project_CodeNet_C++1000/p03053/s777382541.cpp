#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
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

char s[maxn][maxn];

const int kx[4]={0,0,1,-1};
const int ky[4]={1,-1,0,0};

queue <int> qx,qy;
int d[maxn][maxn],n,m;

int main()
{
	n=read(); m=read(); rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) d[i][j]=inf;
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='#') qx.push(i),qy.push(j),d[i][j]=0;
	while(!qx.empty())
	{
		int x=qx.front(),y=qy.front(); qx.pop(); qy.pop();
		rep(k,0,3)
		{
			int tx=x+kx[k],ty=y+ky[k];
			if(tx<=0||tx>n||ty<=0||ty>m) continue;
			if(d[tx][ty]!=inf) continue;
			d[tx][ty]=d[x][y]+1; qx.push(tx); qy.push(ty);
		}
	}
	int ans=0;
	rep(i,1,n) rep(j,1,m) ans=max(ans,d[i][j]);
	cout<<ans<<endl;
	return 0;
}