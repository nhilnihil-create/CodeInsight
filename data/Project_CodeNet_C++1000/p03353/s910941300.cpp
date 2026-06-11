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
    string s; cin >> s;
    int K; cin >> K;
    int n = s.size();
    set<string> ans;

    rep(i,n){
        string t;
        rep(j,K){
            if (i+j < n){
                t += s[i+j];
                ans.insert(t);
            }
        }
    }

    //sort(ans.begin(), ans.end());
    
    for(auto a : ans){
        if (--K == 0) {
            cout << a << endl;
            break;
        }
    }

   // cout << ans[K-1] << endl;
    

}
