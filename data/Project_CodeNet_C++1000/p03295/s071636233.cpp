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
    vector<P> c(m);
    rep(i,m) {
        cin >> c[i].second >> c[i].first;
    }
    sort(c.begin(), c.end());
    int ans = 0;
    int now = -1;
    rep(i,m) {
        if (c[i].second <= now) continue;
        ans++;
        now = c[i].first - 1;
    }
    cout << ans << endl;
    return 0;
}