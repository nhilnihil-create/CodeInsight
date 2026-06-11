#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, c, d, i = 8;
	char p[] = {'+', '-'};
	scanf("%1d%1d%1d%1d", &a, &b, &c, &d);
	while (i--)
		if (a+(i&4?-b:b)+(i&2?-c:c)+(i&1?-d:d) == 7)
		{
			printf("%d%c%d%c%d%c%d=7\n",a,p[i/4%2],b,p[i/2%2],c,p[i%2],d);
			return 0;	
		}
}
