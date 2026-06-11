/*
Author: Xjrjyy
LANG: C++
PROG: agc021_a.cpp
Mail: admin@xjrjyy.com
Blog: https://blog.xjrjyy.cn/
*/

#include <cstdio>
#include <cctype>
#include <vector>
#include <iostream>

#define MAXN ()

long long n;
int ans, ans2;

int main()
{
    scanf("%lld", &n);
    while (n >= 10)
    {
        ans += n % 10;
        ans2 += 9;
        n /= 10;
    }
    ans += n;
    ans2 += n - 1;
    printf("%d\n", std::max(ans, ans2));
    return 0;
}
