#include <bits/stdc++.h>
using namespace std;

int q;
long long a, b;

int main()
{
	scanf("%d", &q);
	while(q--)
	{
		scanf("%lld%lld", &a, &b);
		long long temp=sqrt(a*b);
		if(temp*temp==a*b)
		{
			if(a==b)
			{
				printf("%d\n", temp*2-2);
				continue;
			}
			else 
			{
				printf("%d\n", temp*2-3);
				continue;
			}
		}
		if(temp*(temp+1)>=a*b) printf("%d\n", temp*2-2);
		else printf("%d\n", temp*2-1);
	}
}