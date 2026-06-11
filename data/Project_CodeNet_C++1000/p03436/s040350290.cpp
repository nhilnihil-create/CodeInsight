#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

const ll INF = 1001001001;

ll d[55][55];
string s[55];
ll dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

int main() {
    ll h, w;
    cin >> h >> w;
    ll white = 0;
    for (ll i = 0; i < h; i++) {
        cin >> s[i];
        for (ll j = 0; j < w; j++) {
            if (s[i][j] == '.') white++;
        }
    }
    for (ll i = 0; i < 55; i++) {
        for (ll j = 0; j < 55; j++) {
            d[i][j] = INF;
        }
    }
    queue<P> que;
    que.push(P(0, 0));
    d[0][0] = 1;
    while (que.size()) {
        P p = que.front(); que.pop();
        ll cy = p.first, cx = p.second;
        for (ll i = 0; i < 4; i++) {
            ll ny = cy + dy[i], nx = cx + dx[i];
            if (0 <= ny && ny < h && 0 <= nx && nx < w && d[ny][nx] == INF && s[ny][nx] == '.') {
                d[ny][nx] = d[cy][cx] + 1;
                que.push(P(ny, nx));
            }
        }
    }
    if (d[h - 1][w - 1] == INF) cout << -1 << endl;
    else cout << white - d[h - 1][w - 1] << endl;
}