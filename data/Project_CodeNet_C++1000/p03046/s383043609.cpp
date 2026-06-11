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

int n,k;

int main()
{
	cin>>n>>k; int p=pow(2,n)-1;
	if(k==0)
	{
		for(int i=0;i<=p;i++) printf("%d %d ",i,i);
		return 0;
	}
	if(k>p) return puts("-1"),0;
	int nw=0;
	for(int i=0;i<=p;i++) if(i!=k) nw^=i;
	if(nw!=k) puts("-1");
	else
	{
		for(int i=0;i<=p;i++) if(i!=k) printf("%d ",i); printf("%d ",k);
		for(int i=p;i>=0;i--) if(i!=k) printf("%d ",i); printf("%d ",k);
	}
	return 0;
}