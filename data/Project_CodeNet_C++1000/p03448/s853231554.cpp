#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i <= n; i++)
typedef long long ll;
using namespace std;

int main() {
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int ans = 0;
    rep(a, A) rep(b, B) rep(c, C) {
        if (a * 500 + b * 100 + c * 50 == X && a + b + c >= 1) ans++;
    }

    cout << ans << endl;
    return 0;
}
