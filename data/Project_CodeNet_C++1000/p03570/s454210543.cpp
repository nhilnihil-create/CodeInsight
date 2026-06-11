#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define fore(i,a) for(auto &i:a)
#pragma GCC optimize ("-O3")
using namespace std; void _main(); int main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
//---------------------------------------------------------------------------------------------------
/*---------------------------------------------------------------------------------------------------
　　　　　　　　　　　 ∧＿∧  
　　　　　 ∧＿∧ 　（´<_｀ ）　 Welcome to My Coding Space!
　　　　 （ ´_ゝ`）　/　 ⌒i     
　　　　／　　　＼　 　  |　|     
　　　 /　　 /￣￣￣￣/　　|  
　 ＿_(__ﾆつ/　    ＿/ .| .|＿＿＿＿  
　 　　　＼/＿＿＿＿/　（u　⊃  
---------------------------------------------------------------------------------------------------*/




typedef long long ll;
#define INF INT_MAX/2
string S; int N;
unordered_map<ll, int> dp;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> S; N = S.length();

    ll x = 0;
    dp[0] = 0;
    int ans = 0;
    rep(i, 0, N) {
        x ^= 1LL << (S[i] - 'a');
        
        int ma = INF;
        if (!dp.count(x)) dp[x] = INF;
        ma = min(ma, dp[x]);

        rep(i, 0, 26) {
            ll xx = x ^ (1LL << i);
            if (!dp.count(xx)) dp[xx] = INF;
            ma = min(ma, dp[xx]);
        }

        dp[x] = min(dp[x], ma + 1);
        ans = ma + 1;
    }

    cout << ans << endl;
}