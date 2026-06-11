#include <bits/stdc++.h>

using namespace std;

int A, B, C, X, Y;

void solve() {
    int res = pow(10, 9);
    for (int i = 0; i <= max(X, Y) * 2; ++i) {
        res = min(
                (int) (C * i
                       + A * max(0, (int) round(X - i * 0.5))
                       + B * max(0, (int) round(Y - i * 0.5))),
                res);
    }
    printf("%d\n", res);
}

int main() {
    cin >> A >> B >> C >> X >> Y;
    solve();
    return 0;
}