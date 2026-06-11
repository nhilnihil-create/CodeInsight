#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int check(int start, int x, int **bit)
{
    for (int i = 0; i < 20; i++)
        if (bit[x][i] - bit[start][i] >= 2)
            return 0;
    return 1;
}

int bisect(int start, int x, int y, int **bit)
{
    if (y - x == 1)
        return x;
    int mid = (y - x) / 2 + x;
    if (check(start, mid, bit))
        return bisect(start, mid, y, bit);
    else
        return bisect(start, x, mid, bit);
}


int main(void)
{
    int N;
    scanf("%d", &N);
    int *L = (int *) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf("%d", &L[i]);
    int **bit = (int **) malloc((N + 1) * sizeof(int *));
    for (int i = 0; i < N + 1; i++)
        bit[i] = (int *) calloc(20, sizeof(int));

    for (int j = 0; j < N; j++)
        for (int i = 0; i < 20; i++)
            bit[j + 1][i] = (L[j] >> i) & 1;
    for (int j = 1; j < N; j++)
        for (int i = 0; i < 20; i++)
            bit[j + 1][i] += bit[j][i];

    long cnt = 0;

    for (int i = 0; i < N; i++)
        cnt += bisect(i, i, N + 1, bit) - i;
    printf("%ld\n", cnt);
}
