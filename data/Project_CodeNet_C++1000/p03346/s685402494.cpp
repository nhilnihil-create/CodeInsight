#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005;

int n,a[MAXN],b[MAXN],f[MAXN];

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)
	{
		readint(a[i]);
		b[a[i]]=i;
	}
	int ans=0;
	for(int i=n;i;--i)
	{
		if(b[i+1]>b[i])f[i]=f[i+1]+1;
		else f[i]=1;
		chkmax(ans,f[i]);
	}
	printf("%d\n",n-ans);
	return 0;
}