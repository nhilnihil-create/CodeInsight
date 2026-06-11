#include<bits/stdc++.h>
using namespace std;
/*******  All Required define Pre-Processors and typedef Constants *******/
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.rbegin(), cont.rend()
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep1(i,n) for(int i=1; i<=(n); ++i)
#define Dcout(a) cout << setprecision(20) << a << endl
#define MP make_pair
#define PB push_back
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
using ll = long long;
using PAIR = pair<int, int>;
using Graph = vector<vector<int>>;
const double pi=acos(-1.0);
#define debug cout << "line : " << __LINE__ << " debug" << endl
/****** Template of some basic operations *****/
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/**************************************/
/******** User-defined Function *******/
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
/**************************************/
/********** Main()  function **********/
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H,W; cin >> H >> W;
    vector<string> table(H);
    rep(i,H) cin >> table[i];
    int black = 0;
    rep(i,H){
        rep(j,W){
            if(table[i][j] == '#') black++;
        }
    }

    vector<vector<int>> dist(H,vector<int>(W));
    rep(i,H)rep(j,W) dist[i][j] = -1;

    queue<pair<int,int>> que;
    dist[0][0] = 0;
    que.push({0,0});
    while(!que.empty()){
        pair<int,int> v = que.front(); que.pop();
        rep(i,4){
            int nx = v.second + dx[i];
            int ny = v.first + dy[i];
            if(nx<0 || nx>=W || ny<0 || ny>=H) continue;
            if(dist[ny][nx]!=-1) continue;
            if(table[ny][nx]=='#') continue;

            dist[ny][nx] = dist[v.first][v.second] + 1;
            que.push({ny, nx});
        }
    }

    if(dist[H-1][W-1]==-1){
        cout << -1 << endl;
    }else{
        cout << H*W - (black+dist[H-1][W-1] + 1) << endl;
    }
 
}
/********  Main() Ends Here *************/
