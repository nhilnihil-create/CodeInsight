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
int n,sx,sy,h,w;char s1[N+5],s2[N+5];
int main()
{
	scanf("%d%d%d%d%d%s%s",&h,&w,&n,&sx,&sy,s1+1,s2+1);
	RI u=0,d=h+1,l=0,r=w+1;for(RI i=n;i&&d-u>1&&r-l>1;--i)
		s2[i]=='U'?d<=h&&++d:(s2[i]=='D'?u^1&&--u:(s2[i]=='L'?r<=w&&++r:l^1&&--l)),
		s1[i]=='U'?++u:(s1[i]=='D'?--d:(s1[i]=='L'?++l:--r));
	return puts(u<sx&&sx<d&&l<sy&&sy<r?"YES":"NO"),0;
}