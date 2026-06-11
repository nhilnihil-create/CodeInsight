#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
    int A, B, C, X, ans = 0;
    cin >> A >> B >> C >> X;
    rep(i, A + 1) {
        rep(j, B + 1) {
            rep(k, C + 1) {
                if (500 * i + 100 * j + 50 * k == X) ans++;
            }
        }
    }
    cout << ans << "\n";
}