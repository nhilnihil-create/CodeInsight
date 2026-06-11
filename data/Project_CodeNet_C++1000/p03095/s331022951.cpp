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
int n,c[30];char s[N+5];
I int QP(RI x,RI y) {RI t=1;W(y) y&1&&(t=1LL*t*x%X),x=1LL*x*x%X,y>>=1;return t;}
int main()
{
	RI i,f=1;for(scanf("%d%s",&n,s+1),i=1;i<=n;++i) f=1LL*(QP(c[s[i]&31]+1,X-2)+1)*f%X,++c[s[i]&31];
	return printf("%d\n",f-1),0;
}