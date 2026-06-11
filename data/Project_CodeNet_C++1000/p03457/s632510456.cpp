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

bool solve(int n, vector<int> &t, vector<int> &x, vector<int> &y) {
    rep(i, n) {
        if (i == 0) {
            if (x[i] + y[i] > t[i]) return false;
            else if ((t[i] - (x[i] + y[i])) % 2 == 1) return false;
        } else {
            int diff_x = abs(x[i] - x[i-1]);
            int diff_y = abs(y[i] - y[i-1]);
            int diff_t = t[i] - t[i-1];
            if (diff_x + diff_y > diff_t) return false;
            else if ((diff_t - (diff_x + diff_y)) % 2 == 1) return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> t(n), x(n), y(n);
    rep(i, n) {
        cin >> t[i] >> x[i] >> y[i];
    }
    if (solve(n, t, x, y)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}