#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100000
#define X 1000000007
using namespace std;
int n,a[N+5],s[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(i=1;i<=n;++i) s[i]=(s[i-1]+QP(i,X-2))%X;
	RI ans=0;for(i=1;i<=n;++i) ans=(1LL*a[i]*(s[i]+s[n-i+1]-1)+ans)%X;
	for(i=1;i<=n;++i) ans=1LL*ans*i%X;return printf("%d\n",ans),0;
}