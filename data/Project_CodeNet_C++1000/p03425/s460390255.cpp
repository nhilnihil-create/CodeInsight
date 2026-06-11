#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
using ll = long long;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    string t = "MARCH";
    ll cnt[5] = {0};
    rep(i, n) {
        string s;
        cin >> s;
        rep(j, t.size()) {
            if (s[0] == t[j])
                ++cnt[j];
        }
    }

    ll ans = 0;
    rep(i, 5) {
        rep(j, 5) {
            if (i == j)
                continue;
            vector<bool> flag(5);
            flag[i] = flag[j] = true;

            ll now = cnt[i] * cnt[j];
            rep(k, 5) {
                if (!flag[k])
                    ans += now * cnt[k];
            }
        }
    }

    cout << ans / 6 << endl;

    return 0;
}