#include <bits/stdc++.h>
#define fastio (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long int;
using namespace std;

int main() {
    fastio;
    int a, b, x;
    cin >> a >> b >> x;
    for (int i = a; i <= a + b; i++) {
        if (x == i) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
}