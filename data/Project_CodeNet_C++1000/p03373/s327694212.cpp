#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
using P = pair<int, int>;

int choice(int A, int B, int X, int Y) {
    if (X > Y) return A;
    if (X < Y) return B;
}

int main() {

    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;

    if (2*C - A - B >= 0) cout << A * X + B * Y << endl;
    else {
        int n = min(X, Y);
        int N = max(X, Y);
        int aorb = choice(A, B, X, Y);
        cout << min(2 * C * N, 2 * C * n + (N - n) * aorb) << endl;
    }

    return 0;
}