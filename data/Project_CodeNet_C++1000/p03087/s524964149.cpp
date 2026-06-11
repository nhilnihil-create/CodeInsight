#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using ll = long long;
#define rep(inc, bgn, end) for (int inc = bgn; inc < end; ++inc)
#define repe(inc, bgn, end) for (int inc = bgn; inc <= end; ++inc)

using namespace std;

#define PI 3.141592

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    // vector<int> ac;
    vector<int> accnt(n);

    // n
    rep(i, 0, n) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            if (i == 0) {
                accnt[i] = 1;
            } else {
                accnt[i] = accnt[i - 1] + 1;
            }
        } else {
            if (i == 0) {
                accnt[i] = 0;
            } else {
                accnt[i] = accnt[i - 1];
            }
        }
    }

    // rep(i, 0, n) {
    //     cout << accnt[i];  //<< " ";
    // }

    // q
    rep(i, 0, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int cnt = accnt[r] - accnt[l] + 1;
        // lがacの間
        if (accnt[l - 1] == accnt[l]) {
            cnt--;
        }
        if (accnt[r - 1] != accnt[r]) {
            cnt--;
        }

        cout << cnt << endl;
    }

    return 0;
}
