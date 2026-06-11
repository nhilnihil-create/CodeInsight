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

int f(int x){
    if (x % 100 != 0) return 0;
    return f(x/100)+1;
}

int main(){
    int D, N; cin >> D >> N;

    int count = 0;
    int current = 1;
    int ans = 0;
    while (true){
        if (f(current) == D) count++;
        if (count == N){
            ans = current;
            break;
        }
        current++;
    }
    
    cout << ans << endl;
}

