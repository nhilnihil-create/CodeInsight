#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int h,w;
vector<string>board;

ll solve(){
    ll ans = 0;
    vector<vector<ll>>dist(h, vector<ll>(w,-1));
    queue<pii>que;
    rep(i, 0, h){
        rep(j, 0, w){
            if(board[i][j]=='#'){
                dist[i][j]=0;
                que.push(pii(i, j));
            }
        }
    }
    while(!que.empty()){
        pii now = que.front();
        que.pop();
        int x = now.first;
        int y = now.second;
        rep(i, 0, 4){
            int nx = x + dx[i];
            int ny = y + dy[i]; 
            //cout << nx << " " << ny << " " << endl;
            if(nx>=h || nx<0 || ny>=w || ny<0)continue;
            if(dist[nx][ny]==-1){
                dist[nx][ny] = dist[x][y]+1;
                que.push(pii(nx,ny));
                //cout << i << endl;
            }
        }
    }
    rep(i, 0, h){
        rep(j, 0, w){
            ans = max(ans, dist[i][j]);
            //cout << dist[i][j] << endl;
        }
    }
    return ans;
}
int main() {
    cin >> h >> w;
    board.resize(h);
    rep(i, 0, h){
        cin >> board[i];
    }
    cout << solve() << endl;
}