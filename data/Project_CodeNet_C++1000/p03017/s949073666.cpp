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
int n,A,B,C,D;char s[N+5];
int main()
{
	RI i;scanf("%d%d%d%d%d%s",&n,&A,&B,&C,&D,s+1);
	for(i=A;i^C;++i) if(s[i]=='#'&&s[i+1]=='#') return puts("No"),0;
	for(i=B;i^D;++i) if(s[i]=='#'&&s[i+1]=='#') return puts("No"),0;
	if(C>D)
	{
		RI f=0;for(i=B;i<=D&&!f;++i) s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'&&(f=1);
		if(!f) return puts("No"),0;
	}return puts("Yes"),0;
}