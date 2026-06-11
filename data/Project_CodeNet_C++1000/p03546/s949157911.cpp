#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int H,W;
    cin >> H >> W;
    vec<vec<int>> G(10,vec<int>(10));
    rep(i,10)rep(j,10){
        int d;
        cin >> d;
        G[i][j] = d;
    }
    vec<vec<int>> mn(10,vec<int>(10,(int)1e9));

    function<void(int,int,int)> dfs = [&](int start,int now, int starttonowd) {
        if(now==1){
            mn[start][1] = min(mn[start][1],starttonowd);
        } else {
            if(mn[start][now] <= starttonowd) return;
            mn[start][now] = starttonowd;
            for(int i=0;i<=9;++i){
                dfs(start,i,starttonowd+G[now][i]);
            }
        }
    };
    rep(i,10) dfs(i,i,0);
    ll ans = 0;
    rep(i,H*W){
        int k;cin >> k;
        if(k==-1)continue;
        ans+=mn[k][1];
    }
    cout << ans << endl;
}