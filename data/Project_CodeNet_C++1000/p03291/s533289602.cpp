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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string hoge; cin >> hoge;
    int slen = hoge.length();
    string s = "0";
    s += hoge;

    // sをi文字目まで見て、カウントをjまでつけるような場合の数
    vector< vector<ll> > dp(100005, vector<ll>(4, 0));
    dp[0][0] = 1;

    for(int i=0; i<slen; ++i){
        for(int j=0; j<4; ++j){
            if(s[i+1] != '?') dp[i+1][j] += dp[i][j];
            else { dp[i+1][j] += 3*dp[i][j]; chmod(dp[i+1][j]); }
        }
        if(s[i+1] == 'A'){
            // count
            dp[i+1][1] += dp[i][0];
        }
        else if(s[i+1] == 'B'){
            // count
            dp[i+1][2] += dp[i][1];
        }
        else if(s[i+1] == 'C'){
            // count
            dp[i+1][3] += dp[i][2];
        }
        else{
            // count
            dp[i+1][1] += dp[i][0];
            dp[i+1][2] += dp[i][1];
            dp[i+1][3] += dp[i][2];
        }

        for(int j=0; j<4; ++j) chmod(dp[i+1][j]);
    }

    cout << dp[slen][3] << endl;

    // for(int i=0; i<=slen; ++i){
    //     for(int j=0; j<4; ++j){
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    
	return 0;
}
