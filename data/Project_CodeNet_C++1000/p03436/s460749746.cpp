#include <bits/stdc++.h>
#include<math.h>
#include<algorithm> 
#define rep(i,n) for (int i = 0; i < (n) ; ++i)
using namespace std;
using ll = long long ;
using P = pair<int, int> ;
using PL = pair<ll , ll> ;
#define PI 3.14159265358979323846264338327950
#define INF 1e18
#define mod 1000000007
vector<int> mx = {0, 1, 0, -1} ;
vector<int> my = {1, 0, -1, 0} ;

int main(){
    int h, w;
    cin >> h >> w ;
    vector<string> g (h);
    vector<vector<int>> list (h, vector<int> (w, -1)) ;
    rep(i, h) cin >> g[i] ;
    int bk = 0 ;
    rep(i, h){
        rep(j ,w){
            if(g[i][j] == '#'){
                bk++ ;
            }
        }
    }
    queue<P> que ;
    que.push(P(0, 0)) ;
    list[0][0] = 0 ;
    while(!que.empty()){
        P p = que.front() ;
        que.pop() ;
        int x = p.first ;
        int y = p.second ;
        int cost = list[x][y] ;
        if(x == h - 1 && y == w - 1) break ;
        rep(v, 4){
            int nx = x + mx[v] ;
            int ny = y + my[v] ;
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue ;
            if(list[nx][ny] >= 0) continue ;
            if(g[nx][ny] == '#') continue ; 
            list[nx][ny] = cost + 1 ;
            que.push(P(nx, ny)) ;
        }
    }  
    if(list[h - 1][w - 1] == -1) {
        cout << -1 << endl ;
        return 0 ;
    }
    int t = list[h - 1][w - 1] - 1;
    cout << h*w - t - bk - 2 << endl ;
} 