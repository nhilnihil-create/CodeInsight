#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <bitset>
#include <iostream>

int n;
long long ans, m;
long long a[300000];

int main()
{
    ans = 10000000000000000;
    
    scanf("%d %lld", &n, &m);
    
    for (int i = 1; i <= n; ++i)
    {
        scanf("%lld", &a[i]);
        a[i] += a[i - 1];
    }
    
    long long temp;
    int p;
    long long cost, delta;
    for (int k = 1; k <= n; ++k)
    {
        temp = m * k + n * m;
        p = n;
        cost = 3;
        //printf("HERE");
        while (p > 0)
        {
            if (p - k < 0)
                delta = a[p];
            else delta = a[p] - a[p - k];
            temp += delta * cost;
            if (cost == 3) temp += 2 * delta;
            if (temp > ans) break;
            //printf("%I64d\n", temp);
            p -= k;
            cost += 2;
        }
        if (temp < ans) ans = temp;
    }
    printf("%lld\n", ans);
        
    return 0;
}