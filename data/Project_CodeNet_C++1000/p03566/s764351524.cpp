#include <bits/stdc++.h>

int main()
{
    int n, t[101], v[101];
    int *points = new int[41000], *points_limit = new int[41000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", t + i);
    for (int i = 0; i < n; i++)
        scanf("%d", v + i);
    t[n] = v[n] = 0;
    for (int i = 1; i < n; i++)
        t[i] += t[i - 1];
    std::fill(points_limit, points_limit + t[n - 1] * 2 + 1, 1000);
    for (int i = 0; i <= t[0] * 2; i++)
        points_limit[i] = std::min(v[0] * 2, points_limit[i]);
    for (int i = 1; i < n; i++)
        for (int j = t[i - 1] * 2; j <= t[i] * 2; j++)
            points_limit[j] = std::min(v[i] * 2, points_limit[j]);
    points_limit[0] = points_limit[t[n - 1] * 2] = 0;
    for (int i = t[n - 1] * 2 - 1; i >= 0; i--)
    {
        points_limit[i] = std::min(points_limit[i], points_limit[i + 1] + 1);
    }
    for (int i = 1; i <= t[n - 1] * 2 - 1; i++)
    {
        points_limit[i] = std::min(points_limit[i], points_limit[i - 1] + 1);
    }
    long long sum{};
    for (int i = 0; i < t[n - 1] * 2; i++)
        sum += points_limit[i] + points_limit[i + 1];
    printf("%lf\n", (double)sum / 8);
    

    delete[] points;
    delete[] points_limit;
    return 0;
}