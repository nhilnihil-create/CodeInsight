#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
#define MOD 1000000007
#define INF (1 << 30)
#define REP(i, m, n) for(int i = (int)m; i < (int)n; ++i)
#define rep(i, n) REP(i, 0, n)


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0, cnt = 1;
    REP(i, 1, n) {
        if(a[i] == a[i-1]) cnt++;
        else {
            ans += cnt/2;
            cnt = 1;
        }
    }
    ans += cnt/2;

    cout << ans << '\n';
    return 0;
}