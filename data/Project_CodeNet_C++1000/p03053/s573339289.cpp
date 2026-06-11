#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>; 
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
constexpr long long LINF = 1001001001001001001;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int h, w; cin >> h >> w;
    vector<string> grid(h+2);
    rept(i, 1, h+1){
        string s; cin >> s;
        grid[i] = "*" + s + "*";
    }
    grid[0] = "";
    grid[h+1] = "";
    rep(i, w+10){
        grid[0] += "*";
        grid[h+1] += "*";
    }
    /*
    rep(i, h+2){
        rep(j, w+2){
            cout << grid[i][j];
        }cout << ln;
    }
    */
    const int dx[4] = {0,0,-1,1};
    const int dy[4] = {1,-1,0,0};
    vector<vector<int>> costs(h+2, vector<int>(w+2, INF));
    queue<pii> que;
    rept(i, 1, h+1){
        rept(j, 1, w+1){
            if(grid[i][j]=='#'){
                que.push({i, j});
                costs[i][j] = 0;
            }
        }
    }
    while(!que.empty()){
        auto p = que.front(); que.pop();
        int y = p.first, x = p.second;
        rep(k, 4){
            int nx = x + dx[k], ny = y + dy[k];
            if(grid[ny][nx] == '.'){
                grid[ny][nx] = '#';
                costs[ny][nx] = costs[y][x] + 1;
                que.push({ny, nx});
            }
        }
    }
    int res = -INF;
    rept(i, 1, h+1){
        rept(j, 1, w+1){
            chmax(res, costs[i][j]);
        }
    }
    cout << res << ln;
}
    
