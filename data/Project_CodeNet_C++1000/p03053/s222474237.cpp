#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, -1, 0, 1};

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i, h)cin >> s[i];
    vector<vector<int>> d(h, vector<int>(w, 1001001));
    vector<vector<bool>> vis(h, vector<bool>(w, false));
    queue<P> que;
    rep(i, h)rep(j, w){
        if(s[i][j] == '#'){
            d[i][j] = 0;
            vis[i][j] = true;
            que.push(make_pair(i, j));
        }
    }

    int ans = 0;
    while(!que.empty()){
        P p = que.front();
        que.pop();
        int y = p.first;
        int x = p.second;
        rep(i, 4){
            if(y+dy[i]<0 || y+dy[i]>=h)continue;
            if(x+dx[i]<0 || x+dx[i]>=w)continue;
            if(vis[y+dy[i]][x+dx[i]])continue;
            vis[y+dy[i]][x+dx[i]] = true;
            ans = max(d[y][x] + 1, ans);
            d[y+dy[i]][x+dx[i]] = d[y][x] + 1;
            que.push(make_pair(y+dy[i], x+dx[i]));
        }
    }
    cout << ans << endl;
}