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

int n,b[maxn],cnt[maxn],nw;
vector <int> ans;

inline void del(int x){rep(i,x,nw) b[i]=b[i+1];}

int main()
{
	n=read(); rep(i,1,n) b[i]=read();
	rep(x,1,n)
	{
		nw=n-x+1;
		per(i,n,1) if(b[i]==i) {ans.pb(i),del(i); break;}
	}
	if(ans.size()!=n) puts("-1");
	else per(i,(int)ans.size()-1,0) printf("%d\n",ans[i]);
	return 0;
}