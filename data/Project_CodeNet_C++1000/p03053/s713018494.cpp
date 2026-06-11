#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define P pair<ll, ll>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl
#define coel cout << endl
#define pb push_back
#define sz(v) ((int)(v).size())
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;

void print(vector<ll> a){
    int n = a.size();
    for (int j=0;j<n;j++) {
        if (j != n-1) cout << a[j] << " ";
        else cout << a[j] << endl;
    }
}

////////////////////////////////////////////////////////
int kuro[1005][1005];
ll H, W, cnt = 0; 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
string field[1005];
ll d[1005][1005];


ll dfs(){
    rep(i, 0, H) rep(j, 0, W) d[i][j] = -1;
    queue<pair<ll, ll>> qu;
    rep(i, 0, H) rep(j, 0, W){
        if(field[i][j] == '#'){
            qu.push({i, j});
            d[i][j] = 0;
        }
    }
    pair<ll, ll> now;
    ll ne_h, ne_w;
    int z = 0;
    while(!qu.empty()){
        // rep(i, 0, H){
        //     rep(j, 0, W) cout << d[i][j];
        //     cout << endl;
        // }
        // cout << endl;
        now = qu.front(); qu.pop();
        rep(i, 0, 4){
            ne_h = now.first+dy[i], ne_w = now.second+dx[i];
            if(ne_h < 0 || ne_h >= H || ne_w < 0 || ne_w >= W) continue;
            if(d[ne_h][ne_w] != -1) continue;
            d[ne_h][ne_w] = d[now.first][now.second]+1;
            chmax(cnt, d[ne_h][ne_w]);
            qu.push({ne_h, ne_w});
        }
        // z++;
        // if(z == 5) break;
    }
}

int main() {   
    cin >> H >> W;
    rep(i, 0, H) cin >> field[i];

    dfs();

    co(cnt);

    return 0;
}
