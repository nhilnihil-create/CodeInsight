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
    int D; ll G; cin >> D >> G;
    vector<int> p(D), c(D);
    rep(i,D) cin >> p[i] >> c[i];

    ll ans = INF;    
    rep(b, 1<<D){
        ll point = 0;
        ll count = 0;
        vector<bool> Used(D,false);
        rep(i, D){
            int bit = (b >> i);
            if ((bit & 1) == 1){
                point += (i+1)*100*p[i]+c[i];
                count += p[i];
                Used[i] = true;
            }
        }

        if (point >= G){
            ans = min(ans, count);
        }
        else{
            for(int i = D-1; i >= 0; i--){
                if (Used[i]) continue;
                int p_count = p[i];
                while (p_count > 1){
                    point += (i+1)*100;
                    count += 1;
                    p_count--;
                    if (point >= G){
                        ans = min(ans, count);
                        break;
                    }
                }
                if (point >= G){
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

