#include <stdio.h>

int	main()
{
	int	A, B, C;
	long long	K, ans;

	scanf("%d %d %d %lld\n", &A, &B, &C, &K);
	if (K % 2) //odd
		ans = B - A;
	else //even
		ans = A - B;
	if (ans >= 100000000000000000 || ans <= -100000000000000000)
		printf("Unfair\n");
	else
		printf("%lld\n", ans);
	return (0);
}