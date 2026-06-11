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

int ans = 100000000;

int main(){
    int N, Y; cin >> N >> Y;
    int sheets[3] = {10000,5000,1000};

    for(int i = 0; i <= 2000; i++){
        for (int j = 0; j <= 2000; j++){
            int k = N - i - j;
            if (k < 0) break;
            if (sheets[0]*i + sheets[1]*j + sheets[2]*k == Y){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " <<  -1 << " " << -1 << endl;
}
