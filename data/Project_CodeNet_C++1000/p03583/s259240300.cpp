#include <bits/stdc++.h>
typedef long long int LL;
typedef unsigned long long int ULL;
using namespace std;

// 插入此處

int main() {
    int N;
    cin >> N;
    double _N = 4 / (double)N;
    LL h, n, w;
    for (h = 1; h <= 3500; h++) {
        for (n = 1; n <= 3500; n++) {
            double _h = 1 / (double)h;
            double _n = 1 / (double)n;
            w = 1 / (_N - _h - _n);
            if (w > 0 && N * (h * n + n * w + h * w) == 4 * h * n * w) {
                goto ok;
            }
        }
    }
    ok:
    printf("%lld %lld %lld\n", h, n, w);
}
