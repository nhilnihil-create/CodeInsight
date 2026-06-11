#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(m, vector<int>(n));
    rep(i, m) {
        int k;
        cin >> k;
        rep(j, k) {
            int s;
            cin >> s;
            s--;
            a[i][s] = 1;
        }
    }
    vector<int> p(m);
    rep(i, m) cin >> p[i];
    int ans = 0;
    rep(i, 1 << n) {
        bool ok = true;
        rep(j, m) {
            int cnt = 0;
            rep(k, n) {
                if (a[j][k] == 1 && (i & 1 << k)) cnt++;
            }
            if (cnt % 2 != p[j]) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}