#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n+m; i++)
#define ALL(v) v.begin(), v.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    if (B / A > C) {
        cout << C << endl;
    } else {
        cout << B / A << endl;
    }
    return 0;
}
