#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

ll dx[4] ={0,1,0,-1}, dy[4] = {1,0,-1,0};

int main(){
    ll h,w;
    cin >> h >> w;   
    char c[h+2][w+2];
    bool is_visited[h+2][w+2] = {false};
    ll cnt = h*w;
   
    rep(i,0,h+2) rep(j,0,w+2) c[i][j] = '#';

    rep(i,1,h+1){
        rep(j,1,w+1){
            cin >> c[i][j];
            if(c[i][j] == '#') cnt--;
        }
    }

    queue<Pll> q;
    ll d = -LINF;
    is_visited[1][1] = true;
    Pll p = Pll(P(1,1),0);
    q.push(p);
    while(!q.empty()){
        Pll v = q.front();
        q.pop();

        if(v.fs.fs == h && v.fs.sc == w){
            d = v.sc;
            break;
        }

        v.sc++;
        rep(i,0,4){
            v.fs.fs += dx[i]; v.fs.sc += dy[i];
            if(!is_visited[v.fs.fs][v.fs.sc] && c[v.fs.fs][v.fs.sc] == '.') q.push(v);
            is_visited[v.fs.fs][v.fs.sc] = true;
            v.fs.fs -= dx[i]; v.fs.sc -= dy[i];
        }
    }

    if(d != -LINF) cout << cnt  - d - 1 << endl;
    else cout << -1 << endl;
   return 0;
}