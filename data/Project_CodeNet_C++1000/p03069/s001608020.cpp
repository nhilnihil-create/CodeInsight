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
    int N; cin >> N;
    string S; cin >> S;

    
    vector<int> blacks(N+1,0);
    vector<int> whites(N+1,0);
    rep(i,N){
        int black = 0;
        if (S[i] == '#') black++;
        blacks[i+1] = blacks[i] + black;
        whites[i+1] = whites[i] + (1-black);
    }
    
    // iより前を白、i以降を黒にする。
    int ans = 100000000;
    rep(i,N+1){
        int black_count = blacks[i];
        int white_count = whites[N] - whites[i];

        ans = min(ans, black_count+white_count);
    }
    
    cout << ans << endl;
}