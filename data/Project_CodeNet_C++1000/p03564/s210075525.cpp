#include <stdio.h>
int main() 
{
	int N, K;
	scanf("%d",&N);
	scanf("%d",&K);
	int ans = 1;
	
	for (int i = 0; i < N; i++)
	{
		if (ans < K)
		{
			ans *= 2;
		} else {
			ans += K;
		}
	}
	
	printf("%d\n",ans);
	return 0;
}