#include<bits/stdc++.h>
/* #define int long long */
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;
typedef pair<int, int> P;
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 200000;
signed main(){
    int n;
    cin >> n;

    vi money;
    money.push_back(1);
    for(int tmp = 6; tmp <= n; tmp *= 6) money.push_back(tmp);
    for(int tmp = 9; tmp <= n; tmp *= 9) money.push_back(tmp);
    sort(money.begin(), money.end());

    vi dp(100100, INF);
    dp[0] = 0;

    rep(i, n+1){
        rep(j, money.size()){
            if(i+1 - money[j] < 0) continue;
            chmin(dp[i+1], dp[i+1 - money[j]] + 1);
        }
    }

    cout << dp[n] << endl;
}