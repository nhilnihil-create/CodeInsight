#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};
const int INF = 1001001001;


int main() {
    int h,w;
    cin >> h >> w;
    char c[60][60];
    int wsum = 0;
    rep(i,h) rep(j,w) {
        cin >> c[i][j];
        if(c[i][j] == '.') wsum++;
    }
    int dist[60][60];
    rep(i,h) rep(j,w) dist[i][j] = INF;
    queue<P>q;
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty()) {
        P p = q.front();q.pop();
        int x ,y;
        x = p.first; y = p.second;
        rep(i,4) {
            int nx = p.first + dx[i];
            int ny = p.second + dy[i];
            if(ny < 0 || ny >= w || nx < 0 || nx >= h) continue;
            if(c[nx][ny] == '#') continue;
            if(dist[nx][ny] == INF) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
            }
        }
    }
    if(dist[h-1][w-1] == INF) cout << -1 << endl;
    else cout << wsum - dist[h-1][w-1] << endl;
}