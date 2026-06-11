#include <bits/stdc++.h>
#include <math.h>
#include <float.h>
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

int main(){
    int H, W; cin >> H >> W;
    vector<string> A(H);
    rep(i,H) cin >> A[i];

    queue<pair<int, int>> que;
    vector<vector<int>> counter(H, vector<int>(W,-1));
    rep(i,H){
        rep(j,W){
            if (A[i][j] == '#'){
                que.push(make_pair(i,j));
                counter[i][j] = 0;
            }
        }
    }

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    int ans = 0;
    while(!que.empty()){
        auto v = que.front(); que.pop();
        int y = v.first;
        int x = v.second;
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= H || nx >= W) continue;
            if (counter[ny][nx] != -1) continue;
            counter[ny][nx] = counter[y][x]+1;
            que.push(make_pair(ny,nx));
            ans = counter[ny][nx];
        }
    }

    cout << ans << endl;
}