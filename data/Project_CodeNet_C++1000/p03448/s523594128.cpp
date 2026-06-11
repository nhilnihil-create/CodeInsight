#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    int cnt = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                int total = 500 * i + 100 * j + 50 * k;
                if (total == x)
                    cnt++;
            }
        }
    }

    cout << cnt << endl;
}
