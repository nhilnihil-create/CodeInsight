#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define reg register
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
    return x*f;
}
ll ans,A,B,C,X,Y;
ll val(ll i){return i*2ll*C+max(X-i,0ll)*A+max(Y-i,0ll)*B;}
int main()
{
	A=read(),B=read(),C=read(),
	X=read(),Y=read();
	reg int i;
	ans=val(0);
	for(i=1;i<=X||i<=Y;++i)
		ans=min(ans,val(i));
	return 0*printf("%lld\n",ans);
}