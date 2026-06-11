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
    vector<int> x(N), y(N), h(N);
    rep(i,N) cin >> x[i] >> y[i] >> h[i];

    rep(cy,101){
        rep(cx,101){
            int H = -1;
            bool isOK = true;
            rep(i,N){
                if (h[i] > 0){
                    if (H == -1){
                        H = h[i] + abs(x[i]-cx) + abs(y[i]-cy);
                    }
                    else{
                        if (h[i] != H - abs(x[i]-cx) - abs(y[i]-cy)){
                            isOK = false;
                            break;
                        } 
                    }
                }
            }
            if(!isOK) continue;
            rep(i,N){
                if (h[i] == 0){
                    if (H - abs(x[i]-cx) - abs(y[i]-cy) > 0) {
                        isOK = false;
                        break;
                    }
                }
            }
            if (!isOK) continue;
            cout << cx << " " << cy << " " << H << endl;
            return 0;
        }
    }
}

