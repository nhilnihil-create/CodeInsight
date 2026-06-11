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
    int N, K; cin >> N >> K;
    vector<ll> x(N), y(N);
    rep(i,N) cin >> x[i] >> y[i];

    ll ans = INF;
    rep(i,N){
        rep(j,N){
            rep(k,N){
                rep(l,N){
                    ll x1 = x[i];
                    ll x2 = x[j];
                    ll y1 = y[k];
                    ll y2 = y[l];
                    ll count = 0;
                    rep(n,N){
                        if (x1 <= x[n] && x[n] <= x2 && y1 <= y[n] && y[n] <= y2){
                            count++;
                        }
                    }
                    if (count >= K){
                        ans = min(ans, abs(x2-x1)*abs(y2-y1));
                    }
                }
            }
        }
    }

    cout << ans << endl;
}