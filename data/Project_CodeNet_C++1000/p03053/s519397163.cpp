#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
int main(){
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    const int INF = INT_MAX;
    vector<vector<int>> d(h,vector<int>(w,INF));
    queue<pair<int,int>> q;
    rep(i,h) {
        string s;
        cin >> s;
        rep(j,w) {
            if(s[j] == '#') {
                d[i][j] = 0;
                q.push(make_pair(i,j));
            }
        }
    }
    const int dx[4] = {0,0,-1,1};
    const int dy[4] = {1,-1,0,0};
    int ans = 0;
    while(!q.empty()) {
        auto v = q.front();
        int x = v.second;
        int y = v.first;
        q.pop();
        rep(i,4) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= w || ny < 0 || ny >= h) continue;
            if(d[ny][nx] != INF) continue;
            d[ny][nx] = d[y][x]+1;
            chmax(ans,d[ny][nx]);
            q.push(make_pair(ny,nx));
        }
    }
    cout << ans << endl;
}
