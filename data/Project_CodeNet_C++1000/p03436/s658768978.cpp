#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const ll MOD = 1e9 + 7;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


ll h,w;
vector<string> v(50);

bool check(ll x, ll y){
    if(x < 0 || x >= h) return false;
    if(y < 0 || y >= w) return false;
    if(v[x][y] == '#')  return false;
    return true;
};


int main(){

    cin >> h >> w;
    ll ans = h*w;
    vector<vector<int>> d(h,vector<int>(w,-1));

    rep(i,h){
        cin >> v[i];
    }
    rep(i,h){
        rep(j,w){
            if(v[i][j] == '#') ans --;
        }
    }

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    d[0][0] = 0;
    pair<ll,ll> pos = make_pair(0,0);
    queue<pair<ll,ll>> q;

    q.push(pos);

    while(!q.empty()){
        pos = q.front();
        q.pop();

        rep(i,4){
            if(check(pos.first+dx[i],pos.second+dy[i]) && d[pos.first+dx[i]][pos.second+dy[i]] == -1){
                q.push(make_pair(pos.first+dx[i],pos.second+dy[i]));
                d[pos.first+dx[i]][pos.second+dy[i]] = d[pos.first][pos.second] + 1;
            }
        }
    }
    

    if(d[h-1][w-1] == -1) cout << -1;
    else cout << ans - d[h-1][w-1] -1;


}