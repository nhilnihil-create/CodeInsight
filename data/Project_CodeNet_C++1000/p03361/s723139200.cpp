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
    int H, W; cin >> H >> W;
    vector<string> s(H);
    rep(i,H) cin >> s[i];

    int xd[4] = {-1,0,1,0};
    int yd[4] = {0,-1,0,1};
    rep(i,H){
        rep(j,W){
            if (s[i][j] == '.') continue;
            bool isOK = false;
            int y,x;
            rep(k,4){
                y = i+yd[k];
                x = j+xd[k];
                if (0 > x || 0 > y || x >= W || y >= H) continue;
                if (s[y][x] == '#'){
                    isOK = true;
                    break;
                }
            }
            if (!isOK){
                //cout << x << " " << y << endl;
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
}
