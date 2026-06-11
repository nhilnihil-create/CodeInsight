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
    vector<vector<int>> c(3,vector<int>(3));
    rep(i,3){
        rep(j,3){
            cin >> c[i][j];
        }
    }
    for (int a1 = 0; a1 <= 100; a1++){
        int b1 = c[0][0] - a1;
        int b2 = c[0][1] - a1;
        int b3 = c[0][2] - a1;
        int a2 = c[1][0] - b1;
        int a3 = c[2][0] - b1;
        
        vector<int> a = {a1,a2,a3};
        vector<int> b = {b1,b2,b3};

        bool isOK = true;
        rep(i,3){
            rep(j,3){
                if (c[i][j] != a[i]+b[j]){
                    isOK = false;
                }
            }
        }
        if (isOK){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
