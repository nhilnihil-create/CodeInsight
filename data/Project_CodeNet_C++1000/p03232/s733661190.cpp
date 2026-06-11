#include <bits/stdc++.h>
#define BASE 1000000007
using namespace std;

long mod_pow(long a, int r) {
    long ans = 1;
    for (; r > 0; r >>= 1) {
        if (r & 1)
            ans = (ans * a) % BASE;
        a = (a * a) % BASE;
    }
    return ans;
}

long mod_div(long a) {
    return mod_pow(a, BASE - 2);
}

long factorial(long n) {
    long ans = 1;
    for (; n > 0; n--) {
        ans = (ans * n) % BASE;
    }
    return ans;
}

long add(long x, long y) {
    return (x + y) % BASE;
}

long sub(long x, long y) {
    return (BASE + x - y) % BASE;
}

long mul(long x, long y) {
    return (x * y) % BASE;
}

int main() {
    int n;
    scanf("%d", &n);
    long fact_n = factorial(n), invs[n];
    invs[0] = 1;
    for (int i = 1; i < n; i++) {
        invs[i] = add(invs[i - 1], mod_div(i + 1));
    }
    long ans = 0;
    for (int i = 0; i < n; i++) {
        long a;
        scanf(" %ld", &a);
        ans = add(ans, mul(a, mul(fact_n, add(invs[i], sub(invs[n - 1 - i], invs[0])))));
    }
    printf("%ld\n", ans);
    return 0;
}
