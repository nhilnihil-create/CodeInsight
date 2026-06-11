#include <bits/stdc++.h>

using namespace std;

const int max_n = 1000111, inf = 1000111222;

int n, q;
char s[max_n];

long long solve(int k) {
    long long d = 0, m = 0, dm = 0, dmc = 0;
    for (int i = 0; i < n; ++i) {
        if (i - k >= 0) {
            if (s[i - k] == 'D') {
                dm -= m;
                --d;
            } else if (s[i - k] == 'M') {
                --m;
            }
        }
        if (s[i] == 'D') {
            ++d;
        } else if (s[i] == 'M') {
            dm += d;
            ++m;
        } else if (s[i] == 'C') {
            dmc += dm;
        }
    }
    return dmc;
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d%s%d", &n, s, &q);
    while (q--) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", solve(k));
    }
    return 0;
}
