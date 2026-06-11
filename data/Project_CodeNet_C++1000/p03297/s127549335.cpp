#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define int long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int A,B,C,D,E,F;
main()
{
	int T;re(T);
	while(T--)
	{
		re(A);re(B);re(C);re(D);
		if(A<B || D<B)
		{
			puts("No");
			continue;
		}
		if(C>=B || !D)
		{
			puts("Yes");
			continue;
		}
		E=__gcd(B,D);
		A%=E;
		C=C-B+1;
		F=C/E*E;
//		printf("%lld %lld %lld\n",E,C,F);
		if(F-E+A>=C)F=F-E+A;
		else F+=A;
		puts(F<0?"No":"Yes");
	}	
}
/*
must A>=B  A%=B
must A<=C
must D>=B  D%=B
if C>=B ok
if C<B

(A + xD)%B > C 
D> B-A
*/