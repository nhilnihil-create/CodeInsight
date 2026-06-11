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

int main(){
    int N, C; cin >> N >> C;
    vector<vector<int>> D(C, vector<int>(C));
    rep(i,C){
        rep(j,C){
            cin >> D[i][j];
        }
    }

    vector<vector<int>> c(N,vector<int>(N));
    rep(i,N){
        rep(j,N){
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vector<vector<ll>> sum(3, vector<ll>(C,0));
    rep(i,C){
        rep(j,N){
            rep(k,N){
                int x = j+1;
                int y = k+1;
                sum[(x+y)%3][i] += D[c[j][k]][i];
            }
        }
    }

    ll ans = INF;
    rep(i,C){
        rep(j,C){
            if (i == j) continue;
            rep(k,C){
                if (i == k) continue;
                if (j == k) continue;
                ans = min(ans, sum[0][i]+sum[1][j]+sum[2][k]);
            }
        }
    }

    cout << ans << endl;



}
