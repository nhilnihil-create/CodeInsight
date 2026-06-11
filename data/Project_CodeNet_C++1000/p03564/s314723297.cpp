#include <stdio.h>

int main()
{
	int n,k,t=1, ans;
	scanf("%d %d", &n, &k);
	for (int i=1;i<=n;i++)
	{
		if (t<k)
		{
			t=t*2;
		}
		else
		{
			t=t+k;
		}
	}
	printf("%d", t);
	
	
	
	return 0;
}