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
    int N; cin >> N;
    vector<vector<int>> F(N, vector<int>(10));
    rep(i,N){
        rep(j,10){
            cin >> F[i][j];
        }
    }
    vector<vector<int>> P(N, vector<int>(11));
    rep(i,N){
        rep(j,11){
            cin >> P[i][j];
        }
    }

    ll ans = -INF;
    for (int i = 1; i < (1<<10); i++){
        ll benefit = 0;
        vector<int> isOpen(10, 0);
        rep(j,10){
            isOpen[j] = (i >> j) & 1;
        }

        rep(j,N){
            int count = 0;
            rep(k,10){
                if (F[j][k] == 1 && isOpen[k] == 1){
                    count++;
                }
            }
            benefit += P[j][count];
        }
        ans = max(ans, benefit);

    }

    cout << ans << endl;
}