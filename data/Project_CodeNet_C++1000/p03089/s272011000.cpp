#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 100
using namespace std;
int n,a[N+5],s[N+5];
int main()
{
	RI i,j,t;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);for(i=1;i<=n;++i)
	{
		for(t=0,j=1;j<=n-i+1;++j) a[j]==j&&(t=j);if(!t) return puts("-1"),0;
		for(s[n-i+1]=t;t^(n-i+1);++t) a[t]=a[t+1];
	}
	for(i=1;i<=n;++i) printf("%d\n",s[i]);return 0;
}