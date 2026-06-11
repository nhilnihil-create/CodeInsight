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
#define I2 500000004
#define C(x,y) (1LL*Fac[x]*IFac[y]%X*IFac[(x)-(y)]%X)
using namespace std;
int n,a[N+5],Fac,Inv[N+5],s[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
I int f(CI x) {return 1LL*Fac*Inv[x+1]%X;}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(Fac=i=1;i<=n;++i) Inv[i]=QP(i,X-2),Fac=1LL*Fac*i%X;
	RI t=0,ans=0;for(i=2;i<=n;++i) t=(t+f(i-1))%X;
	for(i=1;i<=n;++i) t=(t+f(i-1))%X,ans=(1LL*t*a[i]+ans)%X,t=(t-f(n-i)+X)%X;
	return printf("%d\n",ans),0;
}