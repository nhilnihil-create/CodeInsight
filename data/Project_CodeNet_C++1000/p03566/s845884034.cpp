#include <bits/stdc++.h>
using namespace std;
#define rep(i, l, r) for(int i=(l); i<(r); ++i)
typedef long long ll;
typedef unsigned long long ull;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
 
/* attention
    long longのシフト演算には気をつけよう
    タイポした時のデバッグが死ぬほどきつくなるので変数名は最低3字くらい使った方がいいかも
    sizeは(int)とキャストしよう
    ごちゃごちゃ場合分けを考える前に全探索は考えましたか？
    詰まった時に、別の分野の問題として考え直す（これdpでは？、グラフとしてみればいいのでは？）
    多くの問題はパターンマッチだが、パターンに落とし込むまでが難しく、そのための訓練としてわからない問題をあれこれ色々な角度から考察してみるのではないか
    cin.tie(0);
    ios::sync_with_stdio(false);<- これら、printfとかと併用しない方が良さそう

*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */

int n;
int t[110], v[110], cum[110];

double f(int i, double t){
    if(i==0) return t;
    if(i==n+1) return cum[n]-t;

    if(0<=t && t<=cum[i-1]) return v[i]+(cum[i-1]-t);
    else if(cum[i-1]<t && t<=cum[i]) return v[i];
    else return v[i]+(t-cum[i]);
}

int main(){
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> n;
    rep(i, 1, n+1) cin >> t[i];
    rep(i, 1, n+1) cin >> v[i];
    rep(i, 1, n+1) cum[i] = cum[i-1]+t[i];

    double ans=0.0;
    double a=0.0;
    for(double t=0.5; t<=cum[n]; t+=0.5){
        double b=500.0;
        rep(i, 0, n+2) chmin(b, f(i, t));
        ans += (a+b)*0.25;
        a=b;
    }
    printf("%.10lf\n", ans);
    
    return 0;
}