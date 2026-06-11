#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); i++)
using namespace std;
using ll = int64_t;
using P = pair<int, int>;

constexpr int LEN = 1005;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};
char m[LEN][LEN];
int v[LEN][LEN];

int main(){
    memset(v, 0, sizeof(v));
    int h, w; cin >> h >> w;
    queue<P> q;
    rep(i, h)rep(j, w){
        char c; cin >> c;
        m[i][j] = c;
        if(c == '#') {
            q.push({i, j});
        }
    }

    while(q.size()){
        P now = q.front(); q.pop();
        int i = now.first, j = now.second;
        rep(k, 4){
            int ni = i + di[k], nj = j + dj[k];
            if(0 <= ni && ni < h && 0 <= nj && nj < w && m[ni][nj] != '#'){
                v[ni][nj] = v[i][j] + 1;
                m[ni][nj] = '#';
                q.push({ni, nj});
            }
        }
    }

    int ans = -1;
    rep(i, h)rep(j, w) ans = max(ans, v[i][j]);
    cout << ans << endl;

    return 0;
}