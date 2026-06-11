#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#define LL long long
using namespace std;
LL A,B,C,D;
LL gcd(LL a,LL b) {return a==0?b:gcd(b%a,a);}
int main()
{
	LL T;scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
		if(A<B) {printf("No\n");continue;}
		if(D<B) {printf("No\n");continue;}
		if(C>=B-1) {printf("Yes\n");continue;}
		A%=B;D=(D-B)%B;
		if(A>C) {printf("No\n");continue;}
		LL d=gcd(B,D),len=C-A;
		A=A+len/d*d;
		if(A+d<B) {printf("No\n");continue;}
		else {printf("Yes\n");continue;}
	}
}