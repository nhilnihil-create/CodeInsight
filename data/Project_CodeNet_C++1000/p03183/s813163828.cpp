#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b);
#define chmin(a, b) a = min(a, b);
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

struct Block {
    int w, s, v;
    Block(int w, int s, int v): w(w), s(s), v(v) {}
};

bool blockcmp(Block x, Block y) {
    return x.w + x.s < y.w + y.s; 
}

int main() {
    int n;
    cin >> n;
    vector<Block> b;
    rep(i, n) {
        int w, s, v;
        cin >> w >> s >> v;
        b.emplace_back(w, s, v);
    }
    sort(b.begin(), b.end(), blockcmp);
    vector<ll> dp(10002);
    rep(i, n) {
        int w = b[i].w, s = b[i].s, v = b[i].v;
        for(int j = s; j >= 0; j--) {
            int dest = min(10001, j + w);
            chmax(dp[dest], dp[j] + v);
        }
    }
    ll ans = 0;
    rep(i, 10002) chmax(ans, dp[i]);
    cout << ans << endl;
}
