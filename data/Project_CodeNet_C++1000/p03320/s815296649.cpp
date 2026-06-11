#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef long long i64;

i64 f(i64 x) {
    i64 fx = 0;
    for (; x; fx += x % 10, x /= 10);
    return fx;
}

int main() {
    i64 K, x = 1, fx = 1, nx, fnx;
    scanf("%lld", &K);
    while (K --) {
        printf("%lld\n", x);
        nx = x + 1;
        fnx = f(nx);
        for (i64 dx = 1; dx <= x + 1; dx *= 10) {
            i64 tx = x + dx;
            i64 ftx = f(tx);
            if (nx * ftx > tx * fnx) {
                nx = tx;
                fnx = ftx;
            }
        }
        x = nx;
        fx = fnx;
    }
    return 0;
}