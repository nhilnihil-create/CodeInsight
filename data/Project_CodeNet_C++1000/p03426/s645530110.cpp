#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define rep(i, n) FOR(i, 0, n)
#define whole(x) (x).begin(),(x).end()
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end())
using P = pair<int, int>;
#define debug(var) cerr << "[" << #var << "] " << var << endl
#define chmin(x, y) x = min(x, y)
const ll mod = 1000000007;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};

int dist(P a, P b) {
    return abs(a.first-b.first)+abs(a.second-b.second);
}


int main(){
    int h, w, d;
    cin >> h >> w >> d;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) rep(j, w) {
        cin >> a[i][j];
        a[i][j]--;
    }
    int q;
    cin >> q;
    vector<P> pos(h*w);
    rep(i, h) rep(j, w) {
        pos[a[i][j]] = P(i, j);
    }
    vector<vector<int>> mp(d, vector<int>(1));

    rep(i, h*w) {
        if (i/d==0) continue;
        mp[i%d].push_back(mp[i%d].back()+dist(pos[i], pos[i-d]));
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int x = l%d;
        int ans = mp[x][r/d] - mp[x][l/d];
        cout << ans << endl;
    }
    
    return 0;
}
