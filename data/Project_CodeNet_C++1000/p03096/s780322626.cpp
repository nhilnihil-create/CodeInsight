#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define N 200000
#define X 1000000007
using namespace std;
int n,lst[N+5],f[N+5];
int main()
{
	RI i,x;for(scanf("%d",&n),f[0]=i=1;i<=n;++i) scanf("%d",&x),
		f[i]=f[i-1],lst[x]&&lst[x]^(i-1)&&(f[i]=(f[i]+f[lst[x]])%X),lst[x]=i;
	return printf("%d\n",f[n]),0;
}