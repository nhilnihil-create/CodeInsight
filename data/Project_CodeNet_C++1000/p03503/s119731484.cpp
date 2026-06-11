#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; --i)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};


int main(){
    int n;
    cin >> n;
    vector<int> f(n);
    rep(i, n) {
        rep(j, 10) {
            int x;
            cin >> x;
            f[i] = (f[i]<<1) + x;
        }
    }
    int ans = -mod;
    vector<vector<int>> p(n, vector<int>(11));
    rep(i, n) rep(j, 11) cin >> p[i][j];

    rep(i, 1<<10) {
        if (i==0) continue;
        int res = 0;
        rep(j, n) {
            int num = __builtin_popcount(i&f[j]);
            res += p[j][num];
        }
        chmax(ans, res);
    }
    
    cout << ans << endl;
    return 0;
}
