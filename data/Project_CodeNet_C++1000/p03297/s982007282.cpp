#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t,a,b,c,d;
inline LL work(){
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	if(b>a||b>d)return puts("No"),0;
	LL gcd=__gcd(b,d);
	a%=gcd;
	LL t=c-b+1;
	LL x=a-gcd;
	if(x<t)x+=gcd*((t-x-1)/gcd+1);
	puts(x>=0?"Yes":"No");
}
int main(){
	scanf("%lld",&t);
	while(t--)work();
}