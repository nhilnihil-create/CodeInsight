#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


int main(){
    int h, w;   cin >> h >> w;
    vector<vector<char>> g(h, vector<char>(w));
    ll cnt=0;
    REP(i, h)   
        REP(j, w){
            cin >> g[i][j];
            if(g[i][j]=='.') cnt += 1;
        }
    queue<pair<int, int>> que;
    que.emplace(0, 0);
    vector<vector<ll>> path(h, vector<ll>(w, LINF));
    path[0][0]=1;
    while(!que.empty()){
        pair<int, int> p =que.front();  que.pop();
        REP(i, 4){
            int nx=p.second+dx[i], ny=p.first+dy[i];
            if(nx<0 || ny<0 || h<=ny || w<=nx) continue;
            if(g[ny][nx]=='#') continue;
            if(LINF!=path[ny][nx]) continue;
            que.emplace(ny, nx);
            path[ny][nx] = path[p.first][p.second]+1;
        }
    }
    ll res = cnt - path.back().back();
    if(res<0) res = -1;
    cout << res << endl;
}