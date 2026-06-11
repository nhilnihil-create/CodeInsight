#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int n;
    cin >> n;

    string t = "MARCH";
    vector<ll> cnt(5);
    rep(i, n) {
        string s;
        cin >> s;
        rep(i, t.size()) {
            if (t[i] == s[0])
                cnt[i]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                if (i == k)
                    continue;
                ans += cnt[i] * cnt[j] * cnt[k];
            }
        }
    }
    cout << ans << endl;

    return 0;
}