#include <bits/stdc++.h>
using namespace std;
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
*/

const ll mod = 1e9+7;

void chmod(ll &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

ll modpow(ll x, ll n){
    if(n == 0) return 1;

    ll res = modpow(x, n/2);
    if(n%2 == 0) return res*res%mod;
    else return res*res%mod*x%mod;
}

ll power(ll x, ll n){
    if(n == 0) return 1;

    ll res = power(x, n/2);
    if(n%2 == 0) return res*res;
    else return res*res*x;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <--------------------------------------------> */

typedef tuple<ll, ll, ll> T;

const ll inf = 1LL<<50;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b; cin >> a >> b;
    int h = 100, w = 100;
    vector<vector<char>> fi(110, vector<char>(110));

    for(int i=1; i<=50; ++i) for(int j=1; j<=100; ++j) fi[i][j] = '.';
    for(int i=51; i<=100; ++i) for(int j=1; j<=100; ++j) fi[i][j] = '#';

    --a; --b;
    for(int i=1; i<50; i+=2) for(int j=1; j<100; j+=2){
        if(b==0) break;
        fi[i][j] = '#';
        --b;
    }

    for(int i=52; i<=100; i+=2) for(int j=1; j<100; j+=2){
        if(a==0) break;
        fi[i][j] = '.';
        --a;
    }

    cout << 100 << ' ' << 100 << endl;
    for(int i=1; i<=100; ++i){
        for(int j=1; j<=100; ++j){
            cout << fi[i][j];
        }
        cout << endl;
    }
    
    return 0;
}