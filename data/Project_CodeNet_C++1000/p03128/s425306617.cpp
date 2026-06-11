#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using namespace std;
typedef long long ll;
typedef pair<int, int> pint;

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr int MOD = 1e9 + 7;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(m); rep(i, m) cin >> a[i];

    vector<int> cnt = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    vector<int> dp(n+10, -INF);
    vector<int> prev(n+10, -1);
    dp[0] = 0;
    rep(i, n) {
        rep(j, m) {
            if ((dp[i+cnt[a[j]]] < dp[i] + 1) || ((dp[i+cnt[a[j]]] == dp[i] + 1) && prev[i+cnt[a[j]]] < a[j])) {
                dp[i+cnt[a[j]]] = dp[i] + 1;
                prev[i+cnt[a[j]]] = a[j];
            }
        }
    }

    vector<int> ans;
    int i = n;
    while (i > 0) {
        int num = prev[i];
        ans.push_back(num);
        i -= cnt[num];
    }
    sort(ans.rbegin(), ans.rend());
    rep(i, ans.size()) {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}