#include<cstdio>
#include<iostream>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int n,m,q,brd,mi[N],x,y;
int main()
{
	RI i; for (scanf("%d%d%d",&n,&m,&q),i=1;i<=n;++i) mi[i]=m+1;
	for (i=1;i<=q;++i) scanf("%d%d",&x,&y),mi[x]=min(mi[x],y);
	for (brd=i=1;i<n;++i) if (mi[i+1]<=brd) return printf("%d",i),0;
	else if (brd+1<mi[i+1]) ++brd; return printf("%d",n),0;
}