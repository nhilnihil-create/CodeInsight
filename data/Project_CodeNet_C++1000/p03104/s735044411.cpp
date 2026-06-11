#include <iostream>
using namespace std;

#define DEBUG

long long seriesXor(long long m, long long n)
{
    long long ans = m;
    for (long long i = m + 1; i <= n; i++) {
        ans ^= i;
    }
    return ans;
}

long long calculate(long long x)
{
    if (x % 4 == 0) {
        return x;
    } else if (x % 4 == 1) {
        return 1;
    } else if (x % 4 == 2) {
        return x + 1;
    } else if (x % 4 == 3) {
        return 0;
    } else {
        return 0;
    }
}

int main()
{
    // 输入
    long long a, b, ans = 0;
    scanf("%lld %lld", &a, &b);
    // 计算
    ans = calculate(b) ^ calculate(a - 1);
    // 输出
    printf("%lld\n", ans);
    return 0;
}
