#include <stdio.h>

char a[111][111];

int main(void)
{
	int W, B, i, j;

	scanf("%d %d" ,&W, &B);

	/* . is white, # is black */

	for (i = 0; i < 100; i++)
		for (j = 0; j < 100; j++)
            a[i][j] = (i < 50 ? '.' : '#');

    for (i = 0; i < B - 1; i++)
		a[(i / 50) * 2][(i % 50) * 2] = '#';

	for (i = 0; i < W - 1; i++)
		a[(i / 50) * 2 + 55][(i % 50) * 2] = '.';

	puts("100 100");
	for (i = 0; i < 100; i++)
		puts(a[i]);
	return 0;
}