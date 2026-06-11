#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<62;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// 多次元 vector 生成
template<class T>
vector<T> make_vec(size_t a){
    return vector<T>(a);
}
template<class T, class... Ts>
auto make_vec(size_t a, Ts... ts){
  return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

const int MOD = 1000000007;

int ans = 100000000;

int main(){
    int H, W; cin >> H >> W;

    vector<string> s(H);
    rep(i,H) {
        cin >> s[i];
    }
    int sharp_count = 0;
    rep(i,H){
        rep(j,W){
            if (s[i][j] == '#') sharp_count++;
        }
    }

    vector<vector<int>> dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.push(make_pair(0,0));

    int xd[4] = {-1,0,1,0};
    int yd[4] = {0,-1,0,1};
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        rep(i,4){
            int nx = x + xd[i];
            int ny = y + yd[i];

            if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if(s[ny][nx] == '#') continue;
            if(dist[ny][nx] == -1){
                dist[ny][nx] = dist[y][x] + 1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    if (dist[H-1][W-1] != -1){
        cout << H*W - dist[H-1][W-1] - sharp_count -1 << endl; 
    }
    else{
        cout << -1 << endl;
    }
}
