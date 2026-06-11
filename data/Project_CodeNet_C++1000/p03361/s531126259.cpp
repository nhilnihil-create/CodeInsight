#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

int h, w;
int dx[4]={0, 1, 0, -1}, dy[4]={1, 0, -1, 0};

vector<vector<char>> g;

void dfs(int x, int y){
    g[x][y]='.'; 

    for(int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx<0 || ny<0 || h<=nx || w<=ny || g[nx][ny]=='.') continue;
        dfs(nx, ny);
    }
}


int main(){
    cin >> h >> w;
    g.resize(h, vector<char>(w));
    REP(i, h)   REP(j, w) cin >> g[i][j];


    REP(i, h){
        REP(j, w){
            if(g[i][j]=='#'){
                for(int k=0; k<4; k++){
                    int nx=i+dx[k], ny=j+dy[k];
                    if(nx<0 || ny<0 || h<=nx || w<=ny || g[nx][ny]=='.') continue;
                    dfs(i, j);
                }
            }
        }
    }

    string ans="Yes";
    REP(i, h) REP(j, w) if(g[i][j]=='#') ans= "No";
    
    cout << ans << endl;

}