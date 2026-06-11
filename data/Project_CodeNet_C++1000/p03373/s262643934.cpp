#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    long long ans1, ans2, ans3;
    ans1 = A * X + B * Y;
    if (X < Y) {
        ans2 = 2 * C * X + B * (Y - X);
    } else {
        ans2 = 2 * C * Y + A * (X - Y);
    }
    ans3 = 2 * C * max(X, Y);
    cout << min(ans1, min(ans2, ans3)) << endl;
}