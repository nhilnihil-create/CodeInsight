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
            // a.s - b.w < b.s - a.w
            return a.s + a.w < b.s + b.w;
            });

    ll dp[2*maxS+1];
    memset(dp, 0, sizeof dp);
    for (Block b : block) {
        RFOR(x, min(2*maxS-b.w, b.s), 0) {
            dp[x + b.w] = max(dp[x+b.w], dp[x] + b.v);
        }
    }
    cout << *max_element(dp, dp+2*maxS+1) << '\n';
}

