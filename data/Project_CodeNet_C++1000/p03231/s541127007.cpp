#include <bits/stdc++.h>

using namespace std;
using lint = long long;

int main() {
    lint N, M;
    string s, t;
    cin >> N >> M >> s >> t;

    lint g = __gcd(M, N);
    lint res = N / g * M;
    N /= g, M /= g;
    bool ok = true;
    for (lint i = 0; i < g; ++i) {
        if (s[i * N] != t[i * M]) ok = false;
    }

    if (ok) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}

