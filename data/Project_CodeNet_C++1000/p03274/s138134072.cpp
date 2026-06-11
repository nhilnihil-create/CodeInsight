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
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    int ans = INF;
    rep(i,n) {
        if (i-k+1 < 0) continue;
        int r = i, l = i-k+1;
        int mn = min(abs(x[l]), abs(x[r]));
        int now = x[r]-x[l]+mn;
        ans = min(ans, now);
    }
    cout << ans << endl;
    return 0;
}