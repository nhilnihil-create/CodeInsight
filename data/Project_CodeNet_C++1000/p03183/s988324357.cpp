#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, int> ri3;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define SZ(x) (int)(x).size()
#define ALL(x) begin(x), end(x) 
#define REP(i, n) for (int i = 0; i < n; ++i) 
#define FOR(i, a, b) for (int i = a; i <= b; ++i)
#define RFOR(i, a, b) for (int i = a; i >= b; --i)

struct Block {
    int w, s, v;
};

int main() {
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    Block block[n];
    int maxS = 0;
    FOR(i,0,n-1){
        int w, s, v; cin >> w >> s >> v;
        block[i] = {w, s, v};
        maxS = max(maxS, s);
    }

    sort(block, block+n, [](Block a, Block b) {
            return a.s + a.w < b.s + b.w;
            });

    //for (auto b : block) {
    //    cout << b.w << " " << b.s << " " << b.v << endl;
    //}

    ll dp[n+1][maxS+1];
    memset(dp[n], 0, sizeof dp[n]);
    RFOR(i,n-1,0) FOR(x,0,maxS) {
        dp[i][x] = dp[i+1][x];
        if (block[i].s >= x) {
            int y = x+block[i].w;
            dp[i][x] = max(dp[i][x], (y <= maxS ? dp[i+1][y] : 0) + block[i].v);
        }
        //cout << i << " " << x << " :: " << dp[i][x] << endl;
    }
    cout << dp[0][0] << '\n';
}

