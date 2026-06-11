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
const int MOD = 1000000007;

int main(){
    int N; cin >> N;
    vector<int> h(N);
    rep(i,N) cin >> h[i];

    int ans = 0;
    while(true){
        int left = -1;
        int right = -1;
        int min_v = 10000;
        rep(i,N){
            if (h[i] > 0) min_v = min(min_v, h[i]);
            if (left == -1){
                if (h[i] > 0) left = i;
            }
            else{
                if (h[i] == 0) {
                    right = i-1;
                    break;
                }
            }
        }
        if (right == -1) right = N-1;
        if (min_v == 10000) break;
        
        for(int i = left; i <= right; i++){
            h[i] -= min_v;
        }
        ans += min_v;
    }

    cout << ans << endl;
}

