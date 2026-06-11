#include <bits/stdc++.h>
using ll = long long;
using namespace std;

const int inf = 1e9;
const ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int m, k; cin >> m >> k;

    if (k == 0) {
        for (int i = 0; i < (1 << m); i++) {
            cout << i << ' ' << i << " \n"[i==(1<<m)-1];
        }
    } else if (m == 1) {
        cout << "-1" << '\n';
    } else if (k < (1 << m)) {
        cout << 0 << ' ';
        for (int i = 1; i < (1 << m); i++) {
            if (i == k) continue;
            cout << i << ' ';
        }
        cout << 0 << ' ' << k << ' ';
        for (int i = (1 << m) - 1; i >= 1; i--) {
            if (i == k) continue;
            cout << i << ' ';
        }
        cout << k << '\n';
    } else {
        cout << "-1" << '\n';
    }
    return 0;
}