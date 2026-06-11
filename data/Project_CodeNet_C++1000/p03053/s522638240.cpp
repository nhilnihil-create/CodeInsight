#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int INF = 1e9;
int dp[1000][1000];

int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    queue<P> que;
    rep(i,h){
        cin >> s[i];
        rep(j,w){
            dp[i][j] = INF;
            if(s[i][j] == '#'){
                que.push(P(i,j));
                dp[i][j] = 0;
            }
        }
    }
    int ans = 0;
    while(!que.empty()){
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        rep(k,4){
            int ny = y + dy[k];
            int nx = x + dx[k];
            if(ny < 0 || h <= ny) continue;
            if(nx < 0 || w <= nx) continue;
            if(dp[ny][nx] != INF) continue;
            dp[ny][nx] = dp[y][x] + 1;
            que.push(P(ny, nx));
            chmax(ans, dp[ny][nx]);
        }
    }
    cout << ans << endl;
    return 0;
}
