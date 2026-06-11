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
#define LL long long
using namespace std;
int n;char s[N+5];
int main()
{
	RI i,t=0;LL ans=0;scanf("%s",s+1),n=strlen(s+1);
	for(i=1;i<n;++i) s[i]^'A'?(s[i]=='B'&&s[i+1]=='C'?(++i,ans+=t):(t=0)):++t;
	return printf("%lld\n",ans),0;
}