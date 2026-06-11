#include <bits/stdc++.h>

int main()
{
    int a, b;
    bool *table;
    table = new bool[10000];
    std::fill(table, table + 5000, false);
    std::fill(table + 5000, table + 10000, true);
    scanf("%d%d", &a, &b);
    a--; b--;
    int add = -100;
    for (int i = 0; i < a; i++)
    {
        if (i % 50 == 0) add += 100;
        table[i * 2 + add] = true;
    }
    add = 5000;
    for (int i = 0; i < b; i++)
    {
        if (i % 50 == 0) add += 100;
        table[i * 2 + add] = false;
    }
    printf("100 100\n");
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
            printf("%c", table[i * 100 + j]?'.':'#');
        printf("\n");
    }
    
    delete[] table;
    return 0;
}