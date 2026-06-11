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
    int h, w;
    cin >> h >> w;
    int ans = 0;
    vector<vector<int>> c(10, vector<int>(10));
    rep(i, 10) rep(j, 10) cin >> c[i][j];
    rep(k, 10) rep(i, 10) rep(j, 10) {
        chmin(c[i][j], c[i][k] + c[k][j]);
    }
    rep(i, h) rep(j, w) {
        int a;
        cin >> a;
        if (a!=-1) {
            ans += c[a][1];
        }
    }
    cout << ans << endl;
    return 0;
}
