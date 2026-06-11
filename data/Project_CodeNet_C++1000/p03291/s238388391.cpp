#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const ll MAX_N = 100010;

int main() {
    string s;
    cin >> s;
    ll n = s.size();
    
    /* 文字列sのABC数を「sのうち３文字に丸をつけ、
       丸をつけた文字を左から読むとABCとなるようにする方法」と言い換える*/
    
    vvl dp(n+1, vl(4));  /* dp[i+1][j] : i文字目(iは0-index)までの処理(?の置換と丸つけ)をすでに行っていて
                                         これまでにj個丸をつけているときのsの残りの部分に対する処理を行う方法の数 */
    
    dp[n][3] = 1;
    for(ll i = n-1; i >= 0; i--) {
        for(ll j = 3; j >= 0; j--) {

            ll m1 = 1;
            if(s[i] == '?') {
                m1 = 3;
            }
            
            ll m2 = 0;
            if(s[i] == '?' || (j < 3 && s[i] == "ABC"[j])) {
                m2 = 1;
            }

            if(j == 3) {
                dp[i][j] = m1*dp[i+1][j];
            }
            else {
                // 右辺の第1項はs[i]に丸をつけない場合で、第2項はs[i]に丸をつける場合
                dp[i][j] = m1*dp[i+1][j] + m2*dp[i+1][j+1];
            }

            dp[i][j] %= mod;
        }
    }
    
    out(dp[0][0]);
    re0;
}