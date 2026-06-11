#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

template<typename T>
istream& operator>> (istream& is, vector<T> &vec){
    for(T& x: vec) is >> x;
    return is;
}

int main(){
    ll h, w; cin >> h >> w;
    vector<vector<char>> field(h, vector<char>(w));
    vector<vector<ll>> cnt(h, vector<ll>(w, -1));
    ll white = 0;
    rep(y, h){
        rep(x, w){
            cin >> field[y][x];
            if(field[y][x] == '.') white++;
        }
    }

    queue<pair<ll, ll>> que;
    que.push(make_pair(h-1, w-1));
    cnt[h-1][w-1] = 0;
    ll dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0}; // U L D R
    while(!que.empty()){
        ll tx = que.front().second, ty = que.front().first;
        que.pop();
        rep(i, 4){
            ll nx = tx + dx[i], ny = ty + dy[i];
            if(nx < 0 || nx >= w) continue;
            if(ny < 0 || ny >= h) continue;
            if(field[ny][nx] == '#') continue;
            if(cnt[ny][nx] != -1) continue;
            que.push(make_pair(ny, nx));
            cnt[ny][nx] = cnt[ty][tx] + 1;
        }
    }
    if(cnt[0][0] == -1) cout << -1 << endl;
    else {
        ll ans = (white - 2) - (cnt[0][0] - 1);
        cout << ans << endl;
    }
    return 0;
}