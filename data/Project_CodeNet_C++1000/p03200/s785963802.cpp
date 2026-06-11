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
int n;char s[N+5];
int main()
{
	RI i,t=0;long long ans=0;scanf("%s",s+1),n=strlen(s+1);
	for(i=n;i;--i) s[i]=='W'?++t:(ans+=t);return printf("%lld\n",ans),0;
}