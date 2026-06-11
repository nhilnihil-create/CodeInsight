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
    vector<int> A(N), B(N), C(N);
    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N) cin >> C[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    ll ans = 0;
    rep(i,N){
        ll tmp = 0;
        ll ng =  N;
        ll ok = -1;
        
        while(abs(ok-ng)>1){
            ll mid = (ok+ng) / 2;
        
            if(A[mid] < B[i]) ok = mid;
            else ng = mid;
        }
        tmp += ok+1;

        ng = -1;
        ok = N;
        
        while(abs(ok-ng)>1){
            ll mid = (ok+ng) / 2;
        
            if(C[mid] > B[i]) ok = mid;
            else ng = mid;
        }

        tmp *= (N-ok);
        ans += tmp;
    }
    cout << ans << endl;
}