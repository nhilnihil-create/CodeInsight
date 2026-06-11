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

struct edge{
    int to, cost;
};

int main(){
    int H, W; cin >> H >> W;
    vector<vector<int>> c(10, vector<int>(10));

    rep(i,10){
        rep(j,10){
            cin >> c[i][j];
        }
    }

    rep(k,10){
        rep(i,10){
            rep(j,10){
                c[i][j] = min(c[i][j], c[i][k]+c[k][j]);
            }
        }
    }

    vector<vector<int>> A(H, vector<int>(W,0));
    rep(i,H) rep(j,W) cin >> A[i][j];

    ll ans = 0;
    rep(i,H){
        rep(j,W){
            if (A[i][j] == -1) continue;
            ans += c[A[i][j]][1];
        }
    }

    cout << ans << endl;


}