#include <bits/stdc++.h>
using namespace std;
#define PUTS(x) cout << (x) << endl;
using Int = long long;
Int gcd(Int a, Int b) {
    Int M = max(a, b);
    Int m = min(a, b);
    while (true) {
        Int r = M % m;
        if (r == 0) break;
        M = m;
        m = r;
    }
    return m;
}
int main() {
    Int n, m;
    cin >> n >> m;
    Int g = gcd(n, m);
    Int L = n / g * m;
    Int d = L / g;
    string S, T;
    cin >> S >> T;
    for (Int i = 0;; i += d) {
        auto s = i * n / L;
        auto t = i * m / L;
        if (s >= n || t >= m) break;
        if (S[s] != T[t]) {
            puts("-1");
            return 0;
        }
    }
    PUTS(L);
}
