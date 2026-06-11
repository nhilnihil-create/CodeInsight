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

using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;

ll gcd(ll x, ll y){
    if (y==0) return x;
    else return gcd(y, x%y);
}

int main(){
    int N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> lgcd(N), rgcd(N);
    lgcd[0] = A[0];
    for(int i = 1; i < N; i++){
        lgcd[i] = gcd(lgcd[i-1], A[i]);
    }
    rgcd[N-1] = A[N-1];
    for(int i = N-2; i >= 0; i--){
        rgcd[i] = gcd(rgcd[i+1], A[i]);
    }

    ll ans = 0;
    rep(i,N){
        if(i == 0) ans = max(ans, rgcd[1]);
        else if (i == N-1) ans = max(ans, lgcd[N-2]);
        else ans = max(ans, gcd(lgcd[i-1], rgcd[i+1]));
    }

    cout << ans << endl;
    
}

