#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

int main() {
    int n, y;
    cin >> n >> y;

    int a = -1, b = -1, c = -1;
    bool flg = false;
    // i: 10000の枚数
    for (int i = 0; i <= n; i++) {
        // i: 5000の枚数
        for (int j = 0; j <= n; j++) {
            if (i + j > n) continue;

            // k: 1000の枚数
            int k = n - i - j;
            if (k < 0) continue;

            int m = 10000 * i + 5000 * j + 1000 * k;
            if (m == y) {
                a = i; b = j; c = k;
                flg = true;
                break;
            }
        }
        if (flg) break;
    }

    cout << a << " " << b << " " << c << endl;
}