#include<bits/stdc++.h>
using namespace std;

void solve()
{
	long long A,B,C,D;
	scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
	if (A<B)
	{
		puts("No");
		return;
	}
	if (B>D)
	{
		puts("No");
		return;
	}
	if (B<=C)
	{
		puts("Yes");
		return;
	}
	if (D%B==0)
	{
		puts(A%B>C?"No":"Yes");
		return;
	}
	long long g=__gcd(B,D),a=A%B,c=C%B,tmp=((c+B+g-a)/g*g+a)%B;
	if (tmp>c)
	{
		puts("No");
		return;
	}
	puts("Yes");
}

int main()
{
	int T;
	scanf("%d",&T);
	while (T--) solve();
}