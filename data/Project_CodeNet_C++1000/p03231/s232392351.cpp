#include <bits/stdc++.h>

using namespace std;
using lint = long long;

template<class T>
T GCD(T n, T m) {
    return m ? GCD(m, n % m) : n;
}

int main() {
    lint N, M;
    string s, t;
    cin >> N >> M >> s >> t;

    lint g = GCD(N, M);
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

