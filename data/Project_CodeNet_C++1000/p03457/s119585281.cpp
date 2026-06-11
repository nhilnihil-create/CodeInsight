#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    // cout << "------------------" << endl;

    int n;
    cin >> n;

    vector<int> t(n + 1), x(n + 1), y(n + 1);
    rep(i, n) {
        cin >> t[i + 1] >> x[i + 1] >> y[i + 1];
    }

    bool flg = true;
    rep(i, n) {
        int div = t[i + 1] - t[i] - abs(x[i + 1] - x[i]) - abs(y[i + 1] - y[i]);
// cout << "i: " << i << ", div: " << div << endl;
        if (div < 0) {
            flg = false;
            break;
        }

        if (div % 2 != 0) {
            flg = false;
            break;
        }
    }

    if (flg) cout << "Yes" << endl;
    else cout << "No" << endl;
}