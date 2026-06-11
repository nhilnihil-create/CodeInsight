#include <stdio.h>
int main() {
	int n, k;
	scanf("%d",&n);
	scanf("%d",&k);
	int val = 1;
	
	for (int i = 0; i < n; i++)
	{
		if (val < k)
		{
			val *= 2;
		}
		else
		{
			val += k;
		}
	}
	
	printf("%d",val);
	return 0;
}