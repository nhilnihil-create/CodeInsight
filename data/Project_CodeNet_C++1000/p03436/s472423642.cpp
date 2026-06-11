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


int main(){
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h) cin >> s[i];
    vector<vector<int>> dist(h, vector<int>(w));
    rep(i, h) rep(j, w) dist[i][j] = -1;
    dist[0][0] = 0;
    queue<P> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        P now = q.front();
        q.pop();
        int x = now.first;
        int y = now.second;
        int d = dist[x][y];
        rep(i, 4) {
            int ix = x + dx[i];
            int iy = y + dy[i];
            if (ix<0 || ix>=h || iy<0 || iy>=w) continue;
            if (s[ix][iy]=='#') continue;
            if (dist[ix][iy] != -1) continue;
            dist[ix][iy] = d + 1;
            q.emplace(ix, iy);
        }
    }
    
    int num = 0;
    rep(i, h) rep(j, w) {
        if (s[i][j]=='.') num++;
    }
    if (dist[h-1][w-1]==-1) {
        cout << "-1" << endl;
        return 0;
    }
    int ans = num - (dist[h-1][w-1]+1);
    
    cout << ans << endl;
    return 0;
}
