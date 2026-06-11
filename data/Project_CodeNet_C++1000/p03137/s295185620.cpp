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
    int N,M; cin >> N >> M;
    vector<int> X(M);
    rep(i,M) cin >> X[i];
    sort(X.begin(), X.end());
    ll total = 0;
    total = abs(X[X.size()-1] - X[0]);

    vector<int> diff(M-1,0);
    rep(i,M-1){
        diff[i] = X[i+1] - X[i];
    }
    sort(diff.rbegin(), diff.rend());

    rep(i,N-1){
        if (i >= diff.size()) break;
        total -= diff[i];
    }

    cout << total << endl;

}