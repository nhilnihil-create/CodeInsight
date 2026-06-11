#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int a, b, k;
    cin >> a >> b >> k;

    int diff = (b - a + 1) / 2;
    if (diff < k) {
        for (int i = a; i <= b; i++) cout << i << endl;
    } else {
        for (int i = a; i < a + k; i++) cout << i << endl;
        for (int i = b - k + 1; i <= b; i++) cout << i << endl;
    }
}
