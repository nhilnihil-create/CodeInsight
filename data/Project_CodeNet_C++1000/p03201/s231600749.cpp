#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    ll a[n];
    map<ll, int> cnt;
    rep(i, n) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a, a + n);
    reverse(a, a + n);
    int ans = 0;
    ll cur = 1LL << 33;
    rep(i, n) {
        if (cnt[a[i]] == 0) continue;
        while (a[i] < cur / 2) {
            cur /= 2;
        }
        if (cnt[cur - a[i]] > (cur == a[i] * 2)) {
            ans++;
            cnt[a[i]]--;
            cnt[cur - a[i]]--;
        }
    }
    cout << ans << endl;
    return 0;
}