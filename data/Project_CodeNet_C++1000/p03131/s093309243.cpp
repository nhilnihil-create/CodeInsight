#include <bits/stdc++.h>
using namespace std;

int main() {
    long long k, a, b, tmp1, tmp2, ans1, ans2;
    scanf("%lld%lld%lld", &k, &a, &b);
    tmp1 = k - a - 1;
    if (tmp1 <= -1) {
        printf("%lld\n", k + 1);
        return 0;
    }
    tmp2 = 2;
    ans1 = k + 1;
    ans2 = (tmp1 / tmp2) * (b - a) + b + tmp1 % tmp2;
    printf("%lld\n", max(ans1, ans2));
}