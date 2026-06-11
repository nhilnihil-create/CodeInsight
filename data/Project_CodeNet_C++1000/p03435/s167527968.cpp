#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n-1; i >= 0; i--)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
const int mod = 1e9+7;
const int INF = 1e9;
const int MAX = 1e6;

int main() {
    int a[3], b[3], c[3][3];
    rep(i, 3) {
        rep(j, 3) {
            cin >> c[i][j];
        }
    }
    bool flag;
    for (int i = -100; i <= 100; i++) {
        a[0] = i;
        for (int j = 0; j < 3; j++) {
            b[j] = c[0][j] - a[0];
        }
        flag = true;
        for (int j = 1; j < 3; j++) {
            for (int k = 1; k < 3; k++) {
                if (c[j][k] - b[k] != c[j][k-1] - b[k-1]) {
                    flag = false;
                }
            }
        }
        if (flag) break;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}