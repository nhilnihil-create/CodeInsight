#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
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

int n,m,x[maxn][2],inq[maxn],cnt;
char s[maxn];
vector <int> mp[maxn];
queue <int> q;

int main()
{
	n=read(); m=read(); scanf("%s",s+1);
	rep(i,1,m)
	{
		int u=read(),v=read();
		mp[u].pb(v); mp[v].pb(u); x[u][s[v]-'A']++; x[v][s[u]-'A']++;
	}
	rep(i,1,n) if(x[i][0]==0||x[i][1]==0) q.push(i),inq[i]=1;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<mp[u].size();i++)
		{
			int v=mp[u][i]; if(inq[v]) continue;
			x[v][s[u]-'A']--;
			if(x[v][0]==0||x[v][1]==0) q.push(v),inq[v]=1;
		}
	}
	rep(i,1,n) cnt+=inq[i];
	if(cnt!=n) puts("Yes"); else puts("No");
	return 0;
}