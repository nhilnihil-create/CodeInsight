#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    string S;
    cin >> S;
    int N = sz(S), K;
    cin >> K;
    //dp[i][j][k]:=S[i:j]をk文字まで変更したときの価値の最大値
    int dp[N][N][K+1];
    //操作回数
    rep(i, K+1){
        //幅j
        rep(j, N){
            //スタート地点
            rep(k, N-j){
                if(j <= 2*i) dp[k][k+j][i] = j+1;
                else{
                    if(S[k] == S[k+j]){
                        if(j == 0) dp[k][k+j][i] = 2;
                        else dp[k][k+j][i] = dp[k+1][k+j-1][i]+2;
                    }
                    else{
                        dp[k][k+j][i] = max(dp[k+1][k+j][i], dp[k][k+j-1][i]);
                        if(i > 0){
                            chmax(dp[k][k+j][i], dp[k+1][k+j-1][i-1]+2);
                        }
                    }
                }
            }
        }
    }
    cout << dp[0][N-1][K] << endl;
}