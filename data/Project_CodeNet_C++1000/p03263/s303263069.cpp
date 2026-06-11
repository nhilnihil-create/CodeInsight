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
    int H, W; cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    rep(i,H) rep(j,W) cin >> a[i][j];

    vector<vector<bool>> operated(H, vector<bool>(W,false));
    int ans = 0;
    rep(i,H){
        rep(j,W){
            // 一番下の段以外
            if (i != H-1){
                if (a[i][j]%2==1){
                    a[i][j]--;
                    a[i+1][j]++;
                    operated[i][j] = true;
                    ans++;
                }
            }
            // 一番下の段
            else{
                if(j != W-1){
                    if (a[i][j]%2==1){
                        a[i][j]--;
                        a[i][j+1]++;
                        operated[i][j] = true;
                        ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;
    rep(i,H){
        rep(j,W){
            if (i != H-1){
                if (operated[i][j]){
                    cout << i+1 << " " << j+1 << " " << i+2 << " " << j+1 << endl;
                }
            }
            else{
                if (operated[i][j]){
                    cout << i+1  << " " << j+1 << " " << i+1 << " " << j+2 << endl;
                }
            }
        }
    }
/*
    rep(i,H){
        rep(j,W){
            cout << a[i][j] << "";
        }
        cout << endl;
    }
*/

}