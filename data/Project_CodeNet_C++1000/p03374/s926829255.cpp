#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
const int MN=1e5+5;
ll N,C,X[MN],W[MN];
ll p1,p2,s1,s2,p1m[MN],p2m[MN],s1m[MN],s2m[MN];
int main()
{
	N=read(),C=read();
	int i;
	for(i=1;i<=N;++i) X[i]=read(),W[i]=read();
	X[N+1]=C;
	for(i=1;i<=N;++i){
		p1+=W[i]+X[i-1]-X[i];
		p2=p1-X[i];
		p1m[i]=max(p1m[i-1],p1);
		p2m[i]=max(p2m[i-1],p2);
	}
	for(i=N;i;--i){
		s1+=W[i]-X[i+1]+X[i];
		s2=s1-C+X[i];
		s1m[i]=max(s1,s1m[i+1]);
		s2m[i]=max(s2,s2m[i+1]);
	}
	ll ans=0;
	for(i=1;i<=N;++i)
		ans=max(p2m[i]+s1m[i+1],ans),ans=max(p1m[i],ans);
	for(i=1;i<=N;++i)
 		ans=max(s2m[i]+p1m[i-1],ans),ans=max(s1m[i],ans);
	printf("%lld\n",ans);
 	return 0;
}