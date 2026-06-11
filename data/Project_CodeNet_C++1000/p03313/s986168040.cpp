#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,a1[maxn],a2[maxn],t[maxn],b[10],ans[maxn];

inline void wk(int a,int x)
{
	b[1]=a1[a],b[2]=a2[a],b[3]=a1[x],b[4]=a2[x];
	sort(b+1,b+5); a1[a]=b[4],a2[a]=b[3];
}

int main()
{
	k=read(); n=(1<<k);
	for(int i=0;i<n;i++) t[i]=read(),a1[i]=t[i];
	for(int i=0;i<k;i++) for(int s=0;s<n;s++) if((s&(1<<i))!=0) wk(s,(s^(1<<i)));
	for(int s=1;s<n;s++) ans[s]=max(ans[s-1],a1[s]+a2[s]),printf("%d\n",ans[s]);
	return 0;
}