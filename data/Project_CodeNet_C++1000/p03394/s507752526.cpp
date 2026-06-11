#include <bits/stdc++.h>

int main()
{
    int n, rest_table[4][2][4] = {
        {{2, 3, 4, 6}, {2, 3, 4, 9}},
        {{6}, {3}},
        {{2, 4}, {3, 6}},
        {{2, 4, 6}, {2, 3, 4}}
    };
    scanf("%d", &n);
    if (n == 3)
    {
        printf("2 3 25\n");
        return 0;
    }
    for (int i = 0; i < n - 4; i += 4)
    {
        printf("%d %d %d %d ", i / 4 * 6 + 2, i / 4 * 6 + 3, i / 4 * 6 + 4, i / 4 * 6 + 6);
    }
    int quo_rest = n / 4 % 2, rest = n % 4;
    for (int i = 0; i < (rest + 3) % 4 + 1; i++)
    {
        if (i) printf(" ");
        printf("%d", (n - 1) / 4 * 6 + rest_table[rest][quo_rest][i]);
    }
    printf("\n");

    return 0;
}