#include <bits/stdc++.h>
using namespace std;
typedef long long Int;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    Int sum_a = 0;
    rep(i, n) {
        cin >> a[i];
        sum_a += a[i];
    }
    vector<int> m;
    vector<int> p;
    Int sum_b = 0;
    bool flg = true;
    rep(i, n) {
        cin >> b[i];
        sum_b += b[i];
        if (a[i] - b[i] < 0) {
            m.push_back((a[i] - b[i]) * -1);
            flg = false;
        }
        if (a[i] - b[i] > 0) p.push_back(a[i] - b[i]);
    }
    if (sum_a < sum_b) {
        cout << -1 << endl;
        return 0;
    }
    if (flg) {
        cout << 0 << endl;
        return 0;
    }
    sort(p.rbegin(), p.rend());
    int ans = 1;
    int i_p = 0;
    rep(i, m.size()) {
        while (m[i] > 0) {
            if (p[i_p] > m[i]) {
                p[i_p] -= m[i];
                m[i] = 0;
                ans++;
            }
            else if (p[i_p] == m[i]) {
                m[i] = 0;
                i_p++;
                ans++;
            }
            else {
                m[i] -= p[i_p];
                i_p++;
                ans++;
            }
        }
    }
    cout << ans << endl;
}
