#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



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
    rep(is,1<<n) {
        bool ok = true;
        rep(i,m) {
            int cnt = 0;
            for (int x : s[i]) {
                if (is>>x&1) cnt++;
            }
            cnt %= 2;
            if (cnt != p[i]) ok = false;
        }
        if (ok) ans++;
    }
    cout << ans << endl;
    return 0;
}