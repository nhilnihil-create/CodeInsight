#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)

#define INF 1000000000
#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;

int main() {
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    int H, W;
    cin >> H >> W;
    int sx = 0, sy = 0, gy = H-1, gx = W-1, ans = 0;

    //cin >> sy >> sx;
    //cin >> gy >> gx;
    vector<vi> a(H,vi(W,INF));  //スタート位置からの距離
    vector<string> c(H); //迷路の形状
    queue<P> que;   //探索予定の座標

    rep(i, H){
        cin >> c[i];

        //スタート位置の移動距離距離を0に設定
        rep(j,W){
            if(c[i][j] == '#') {
                a[i][j] = 0;
                que.push(P(i,j));
            }
        }
    }
        
    while(!que.empty()) {
        //現在地の取得
        P cgr = que.front(); que.pop();
        int cx = cgr.second;
        int cy = cgr.first;

         rep(i, 4){
            //チェックする座標の取得
            int chx = cx + dx[i];
            int chy = cy + dy[i];

            //チェックする座標が範囲内
            if(chx >= 0 && chx < W && chy >= 0 && chy < H){
                //チェックする座標が通れる かつ　未探索
                if(a[chy][chx] > a[cy][cx] + 1) {
                    a[chy][chx] = a[cy][cx] + 1;
                    que.push(P(chy, chx));
                }
            }
        }
    }

    rep(i,H)
        rep(j,W)
            ans = max(ans,a[i][j]);

    cout << ans << "\n";
    return 0;
    
}
