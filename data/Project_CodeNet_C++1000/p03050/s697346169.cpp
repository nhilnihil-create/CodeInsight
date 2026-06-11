#include <bits/stdc++.h>

using i64 = long long;

i64 gcd(i64 a, i64 b) { return a ? gcd(b % a, a) : b; }

i64 n;

int main() {
    std::scanf("%lld", &n);
    i64 result = 0;
    for(i64 l = 1, r, x; l <= n; l = r + 1) {
        x = n / l, r = n / x;
        if(x >= r || n % x) continue;
        i64 y = n / x - 1;
        if(y >= l && y <= r) result += y;
    }
    std::printf("%lld\n", result);
}