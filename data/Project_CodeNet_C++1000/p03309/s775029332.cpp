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
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    vector<int> B(N);
    rep(i,N){
        
        B[i] = A[i] - (i+1);
    }

    sort(B.begin(), B.end());
/*
    ll x = B[N/2];
    ll ans = 0;
    rep(i,N){
        ans += abs(A[i]-B[i]);
    }

    cout << ans << endl;

*/

    ll ans = 0;
    rep(i,N){
        ans += abs(B[i]-B[N/2]);
    }
    cout << ans << endl;
/*
    vector<int> median;
    median.push_back(B[(N-1)/2]);
    if (N%2 == 0){
        median.push_back(B[N/2]);
    }
    ll ans = INF;
    ll res = INF;
    rep(i,median.size()){
        ll tmp = 0;
        rep(j,N){
            tmp += abs(A[j]-(median[i]-(i+1)));
        }
        if (res > tmp){
            ans = median[i];
        }
        res = tmp;
    }

    cout << ans << endl;
*/
}

