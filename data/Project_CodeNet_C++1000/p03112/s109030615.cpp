// 7/10
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B, Q;
    cin >> A >> B >> Q;

    vector<ll> s(A), t(B), y(Q);
    rep(i, A) cin >> s[i];
    rep(i, B) cin >> t[i];
    rep(i, Q) cin >> y[i];

    rep(i, Q) {
        ll x = y[i];
        // cin >> x;

        int right1 = lower_bound(s.begin(), s.end(), x) - s.begin();  // xより大きいxのindex。i = Aなら右端、i = 0なら左端
        int left1 = right1 - 1;  // xより小さいxのindex。i = --1なら左側には何もない

        int right2 = lower_bound(t.begin(), t.end(), x) - t.begin();
        int left2 = right2 - 1;

        ll ret = LLONG_MAX;
        ll now;

        // 左側にしか行かない。
        if (left1 != -1 && left2 != -1) {
            now = max(x - s[left1], x - t[left2]);
            ret = min(ret, now);
        }

        // 右側にしか行かない。
        if (right1 != A && right2 != B) {
            now = max(s[right1] - x, t[right2] - x);
            ret = min(ret, now);
        }

        // 神社は左、寺は右
        if (left1 != -1 && right2 != B) {
            now = (x - s[left1]) * 2 + (t[right2] - x);
            ret = min(ret, now);

            now = (x - s[left1]) + (t[right2] - x) * 2;
            ret = min(ret, now);
        }

        // 寺は左、神社は右
        if (left2 != -1 && right1 != A) {
            now = (x - t[left2]) * 2 + (s[right1] - x);
            ret = min(ret, now);

            now = (x - t[left2]) + (s[right1] - x) * 2;
            ret= min(ret, now);
        }

        cout << ret << endl;
    }

    return 0;
}