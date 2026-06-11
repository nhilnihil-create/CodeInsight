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

bool solve(vector<int> &a, vector<int> &b, vector<vector<int>> &c) {
    int n = c.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                b[j] = c[i][j] - a[i];
            } else {
                if (j == 0) continue;
                if (c[i][j] - b[j] != c[i][j-1] - b[j-1]) return false;
            }
        }
    }
    return true;
}

int main() {
    int n = 3;
    vector<int> a(n);
    vector<int> b(n);
    vector<vector<int>> c(n, vector<int>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> c[i][j];
        }
    }
    bool flag;
    for (int i = -100; i <= 100; i++) {
        a[0] = i;
        flag = solve(a, b, c);
        if (flag) break;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}