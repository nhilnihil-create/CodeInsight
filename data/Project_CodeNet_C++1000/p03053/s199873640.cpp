#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int H, W;
    cin >> H >> W;
    string S[H];
    rep(i, H) cin >> S[i];
    int d[H][W];
    queue<int> que;
    rep(i, H) rep(j, W){
        if(S[i][j] == '#'){
            d[i][j] = 0;
            que.push(i*W+j);
        }
        else d[i][j] = inf;
    }
    while(!que.empty()){
        int p = que.front();
        que.pop();
        int x = p/W, y = p%W;
        rep2(i, -1, 1) rep2(j, -1, 1){
            if(abs(i)+abs(j) != 1) continue;
            int nx = x+i, ny = y+j;
            if(nx < 0 || H <= nx || ny < 0 || W <= ny) continue;
            if(chmin(d[nx][ny], d[x][y]+1)) que.push(nx*W+ny);
        }
    }
    int ans = 0;
    rep(i, H) rep(j, W) chmax(ans, d[i][j]);
    cout << ans << endl;
}