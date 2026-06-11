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

int t[505][505], c[505][505];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    rep(i,m) {
        int l, r;
        cin >> l >> r;
        t[l][r]++;
    }
    rep(i,n)rep(j,n) {
        c[i+1][j+1] = c[i+1][j] + t[i+1][j+1];
    }
    rep(i,q) {
        int p, q;
        cin >> p >> q;
        int ans = 0;
        for (int j = p; j <= q; j++) {
            ans += c[j][q];
        }
        cout << ans << endl;
    }
    return 0;
}