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
int n,a[N+5],Fac[N+5],IFac[N+5],s[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
I int f(CI x) {return 1LL*Fac[n-x-1]*Fac[x]%X*C(n,x+1)%X;}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(Fac[0]=i=1;i<=n;++i) Fac[i]=1LL*Fac[i-1]*i%X;
	for(IFac[n]=QP(Fac[n],X-2),i=n-1;~i;--i) IFac[i]=1LL*IFac[i+1]*(i+1)%X;
	for(s[0]=i=1;i<=n;++i) s[i]=(s[i-1]+IFac[i])%X;
	RI t=0,ans=0;for(i=2;i<=n;++i) t=(t+f(i-1))%X;
	for(i=1;i<=n;++i) t=(t+f(i-1))%X,ans=(1LL*t*a[i]+ans)%X,t=(t-f(n-i)+X)%X;
	return printf("%d\n",ans),0;
}