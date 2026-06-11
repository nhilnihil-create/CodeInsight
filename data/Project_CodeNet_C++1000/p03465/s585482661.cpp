#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 4000005
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

int a[maxn],sum,n;
bitset <maxn> s;

int main()
{
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),sum+=a[i]; s[0]=1;
	int tot=(sum+1)/2;
	for(int i=1;i<=n;i++) s|=s<<a[i];
	for(int i=tot;i<=sum;i++) if(s[i]) return cout<<i<<endl,0;
	return 0;
}