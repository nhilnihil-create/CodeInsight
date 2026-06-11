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

ll gcd(ll x, ll y){
    if (y==0) return x;
    else return gcd(y, x%y);
}

int main(){
    ll N, X; cin >> N >> X;
    vector<ll> x(N);
    rep(i,N) cin >> x[i];

    vector<ll> diff(N);
    rep(i,N){
        diff[i] = abs(X-x[i]);
    }
    
    ll ans;
    rep(i,N){
        if (i == 0) ans = diff[i];
        else ans = gcd(ans, diff[i]);
    }

    cout << ans << endl;
}

