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
#define LL long long
using namespace std;
int n,m;LL t;char s1[N+5],s2[N+5];map<LL,char> p;
I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
int main()
{
	RI i;scanf("%d%d%s%s",&n,&m,s1+1,s2+1),t=1LL*n*m/gcd(n,m);
	for(i=1;i<=n;++i) p[(i-1)*(t/n)+1]=s1[i];
	for(i=1;i<=m;++i) if(p.count((i-1)*(t/m)+1)&&p[(i-1)*(t/m)+1]^s2[i]) return puts("-1"),0;
	return printf("%lld\n",t),0;
}