#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;
typedef pair<Int,Int> P;

const Int INF = 100000;

int main(){ 
    Int H, W, num_of_bl = 0; cin >> H >> W;
    vector<vector<bool>> black(H, vector<bool>(W, false));
    vector<vector<Int>> howfar(H, vector<Int>(W, INF));

    rep(i,H) {
        string S;
        cin >> S;
        rep(j,W) {
            if (S[j] == '#') {
                black[i][j] = true;
                num_of_bl++;
            }
        }
    }


    queue<P> que;
    que.push(make_pair(0,0));
    howfar[0][0] = 0;

    while(!que.empty()) {
        P p = que.front();
        Int x, y, nowfar;
        x = p.first;
        y = p.second;
        nowfar = howfar[x][y];
        rep(i,4) {
            Int x1, y1;
            if (i / 2 == 0) {
                x1 = x;
                y1 = y - 1 + 2 * (i % 2);
            }
            else {
                y1 = y;
                x1 = x - 1 + 2 * (i % 2);
            }
            if (x1 < 0 || x1 >= H || y1 < 0 || y1 >= W) continue;
            if ((howfar[x1][y1]==INF)&&(!black[x1][y1])) {
                que.push(make_pair(x1,y1));
                howfar[x1][y1] = nowfar + 1;
            }
        }
        que.pop();
    }


    if (howfar[H-1][W-1] == INF) cout << -1 << endl;
    else cout << H * W - num_of_bl - howfar[H-1][W-1] - 1 << endl;
}