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
    string S; cin >> S;

    int n = S.size();

    int ans = 0;
    int red_count = 0;
    int blue_count = 0;
    rep(i,n){
        if (S[i] == '0') red_count++;
        else blue_count++;
        while (red_count >= 1 && blue_count >= 1){
            ans += 2;
            red_count--;
            blue_count--;
        } 
    }

    cout << ans << endl;
}

