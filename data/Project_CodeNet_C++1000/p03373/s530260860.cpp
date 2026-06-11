#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans;
    if ((A + B) < (2 * C)) {
        ans = A * X + B * Y;
    } else {
        if (X < Y) {
            if (B < 2 * C) {
                ans = 2 * C * X + B * (Y - X);
            } else {
                ans = 2 * C * Y;
            }
        } else {
            if (A < 2 * C) {
                ans = 2 * C * Y + A * (X - Y);
            } else {
                ans = 2 * C * X;
            }
        }
    }
    cout << ans << endl;
}