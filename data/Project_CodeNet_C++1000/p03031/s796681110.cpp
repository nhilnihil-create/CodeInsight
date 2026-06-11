#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    rep(i,m) {
        int k;
        cin >> k;
        rep(j,k) {
            int a;
            cin >> a;
            a--;
            s[i].push_back(a);
        }
    }
    vector<int> p(m);
    rep(i,m) cin >> p[i];
    int ans = 0;
    rep(i,1<<n) {
        bool ok = true;
        rep(j,m) {
            int on = 0;
            for (int u : s[j]) {
                if (i>>u&1) on++;
            }
            if (on%2 != p[j]) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}