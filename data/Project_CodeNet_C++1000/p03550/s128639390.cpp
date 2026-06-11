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

const int inf=1<<29;

vector<vector<int>> d(10, vector<int>(10, inf));

void floyd(){
    rep(k, 0, 10){
        rep(i, 0, 10){
            if(d[i][k]==inf) continue;
            rep(j, 0, 10){
                if(d[j][k]==inf) continue;
                chmin(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, z, w; cin >> n >> z >> w;
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    if(n==1) cout << abs(a[n-1]-w) << endl;
    else cout << max(abs(a[n-1]-w), abs(a[n-2]-a[n-1])) << endl;
    
    return 0;
}