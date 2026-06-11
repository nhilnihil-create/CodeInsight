#include <bits/stdc++.h>

int main()
{
    int n, a[50], min{}, max{}, count{};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a + i);
        if (a[i] < a[min])
            min = i;
        if (a[i] > a[max])
            max = i;
    }
    if (std::abs(a[min]) < std::abs(a[max]))
    {
        for (int i = 0; i < n; i++)
            if (a[i] < 0) count++;
        printf("%d\n", count + n - 1);
        for (int i = 0; i < n; i++)
            if (a[i] < 0)
                printf("%d %d\n", max + 1, i + 1);
        for (int i = 1; i < n; i++)
            printf("%d %d\n", i, i + 1);
    }
    else
    {
        for (int i = 0; i < n; i++)
            if (a[i] > 0) count++;
        printf("%d\n", count + n - 1);
        for (int i = 0; i < n; i++)
            if (a[i] > 0)
                printf("%d %d\n", min + 1, i + 1);
        for (int i = n - 1; i > 0; i--)
            printf("%d %d\n", i + 1, i);
    }
    return 0;
}