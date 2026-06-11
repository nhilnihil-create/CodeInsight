#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    ll h, w, ans = 0; cin >> h >> w;
    vector<string> s(h);
    queue<pair<pair<ll, ll>, ll>> que;
    vvi chk(h, vi(w, 0));

    // 黒の箇所をキューに積む
    rep(i, h){
        cin >> s[i];
        rep(j, w){
            if(s[i][j] == '#'){
                chk[i][j] = INFLL;
                que.push({{i, j}, 0});
            }
        }
    }
    
    // 幅優先探索
    vector<long long> dx = {-1, 1, 0, 0};
    vector<long long> dy = { 0, 0,-1, 1};
    while(que.size()){
        auto top = que.front();
        que.pop();
        rep(d, 4){
            ll x = top.first.second + dx[d];
            ll y = top.first.first + dy[d];
            if(x<0 || y<0 || x>w-1 || y>h-1) continue;
            if(chk[y][x] != 0) continue;
            chk[y][x] = top.second+1;
            chmax(ans, chk[y][x]);
            que.push({{y, x}, top.second+1});
        }
    }
    cout << ans << endl;
}