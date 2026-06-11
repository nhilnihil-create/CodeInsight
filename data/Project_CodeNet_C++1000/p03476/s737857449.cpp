#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1e18;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = b - 1; i >= a; i--)
#define int ll
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

bool chk(int a) {
    if (a == 1) return false;
    if (a == 2 || a == 3) return true;
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) return false;
    }
    return true;
}

signed main() {
    int q;
    cin >> q;
    int a[100100];
    a[0] = 0;
    rep(i, 1, 100100) {
        if (chk(i) && chk((i + 1) / 2)) {
            a[i] = a[i - 1] + 1;
        } else {
            a[i] = a[i - 1];
        }
    }
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        cout << a[r] - a[--l] << "\n";
    }
}