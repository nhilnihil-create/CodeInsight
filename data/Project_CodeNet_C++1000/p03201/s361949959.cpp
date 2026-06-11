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
using namespace std;
int n,a[N+5];map<int,int> s,g;
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i),++s[a[i]];
	RI ans=0,t=1<<30;for(sort(a+1,a+n+1),i=n;i;--i)
	{
		if(g[a[i]]) {--g[a[i]];continue;}--s[a[i]];
		W((a[i]<<1)<t) t>>=1;s[t-a[i]]&&(--s[t-a[i]],++g[t-a[i]],++ans);
	}return printf("%d\n",ans),0;
}