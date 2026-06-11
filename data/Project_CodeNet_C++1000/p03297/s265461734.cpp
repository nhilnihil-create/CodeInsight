#include <bits/stdc++.h>

bool solve();
long long gcd(long long, long long);

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        if (solve()) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

bool solve()
{
    long long a, b, c, d;
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    if (a < b || d < b) return false;
    if (c >= b) return true;
    
    a %= b;
    if (a > c) return false;
    if (d % b == 0) return true;
    d %= b;
    if (c + d < b) return false;

    const long long min_delta{gcd(d, b)};
    if ((b - 1 - a) / min_delta * min_delta + a > c) return false;
    else return true;
}

long long gcd(long long a, long long b)
{
    while (a)
    {
        b %= a;
        std::swap(a, b);
    }
    return b;
}