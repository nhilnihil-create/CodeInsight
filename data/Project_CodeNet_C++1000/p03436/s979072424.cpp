#include <bits/stdc++.h>
using namespace std;
#define REP(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) REP(i, 0, n)
#define rrep(i, n) for (int i = (int)(n-1); i >= 0; i--)
#define sz(x) int(x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define INF 2e9
#define LINF 1e18
#define mod 1000000007
template<class T> inline bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> P;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    int h,w; cin >> h >> w;
    char s[h][w];
    rep(i,h)rep(j,w) cin >> s[i][j];

    int d[h][w];
    rep(i,h)rep(j,w) d[i][j] = INF;
    d[0][0] = 0;

    int num = 0;
    rep(i,h)rep(j,w) {
        if (s[i][j]=='#') num++; //#の数カウント
    }

    queue<P> que;
    que.push(P(0,0));
    while (!que.empty()) {
        P p = que.front(); que.pop();
        if (p.first==h-1 && p.second==w-1) break;
        rep(i,4) {
            int ny = p.first + dy[i];
            int nx = p.second + dx[i];
            if (0<=ny && ny<h && 0<=nx && nx<w && s[ny][nx]!='#' && d[ny][nx]==INF) {
                que.push(P(ny,nx));
                d[ny][nx] = d[p.first][p.second]+1;
            }
        }
    }
    if (d[h-1][w-1]==INF) cout << -1 << endl;
    else cout << h*w - d[h-1][w-1] - num - 1 << endl;
}