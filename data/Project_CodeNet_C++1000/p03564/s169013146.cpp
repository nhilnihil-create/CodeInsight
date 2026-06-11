#include <stdio.h>
int main ()
{
	int N, K;
	scanf ("%d", &N);
	scanf ("%d", &K);
	int hasil = 1;
	for (int i = 0; i < N; i++)
	{
		if (hasil < K)
		{
			hasil *= 2;
		}
		else if (hasil >= K)
		{
			hasil += K;
		}
	}
printf ("%d", hasil);
return 0;
}