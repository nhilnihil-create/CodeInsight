#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int H, W;
    cin >> H >> W;
    vec<vec<int>> G(10, vec<int>(10));
    rep(i, 10) rep(j, 10) {
        int d;
        cin >> d;
        G[i][j] = d;
    }

    function<void(int)> warshall_floyd = [&](int n) {
        for (int k = 0; k < n; k++) {            // 経由する頂点
            for (int i = 0; i < n; i++) {        // 始点
                for (int j = 0; j < n; j++) {    // 終点
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
                }
            }
        }
    };

    warshall_floyd(10);

    int ans = 0;
    rep(i,H*W){
        int k;cin>>k;
        if(k==-1)continue;
        ans+=G[k][1];
    }
    cout << ans << endl;
}