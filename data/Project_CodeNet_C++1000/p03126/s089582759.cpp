#include<stdio.h>
int main()
{
	int n,m,k,d,t,ar[31]={0}, i, count =0;
	scanf("%d %d", &n, &m);
	t=n;
	while(n--)
	{
		scanf("%d", &k);
		while(k--)
		{
			scanf("%d", &d);
			ar[d]++;
		}
	}
	for(i=1; i<=m; i++)
		if(ar[i]==t)
			count++;
	printf("%d\n", count);
	return 0;
}