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
int dp[201010];
unordered_map<ll, int> dp2;
//---------------------------------------------------------------------------------------------------
void _main() {
    cin >> S; N = S.length();

    ll x = 0;
    dp[0] = 0;
    dp2[0] = 0;
    int ans = 0;
    rep(i, 0, N) {
        x ^= 1LL << (S[i] - 'a');
        
        int ma = INF;
        if (!dp2.count(x)) dp2[x] = INF;
        ma = min(ma, dp2[x]);

        rep(i, 0, 26) {
            ll xx = x ^ (1LL << i);
            if (!dp2.count(xx)) dp2[xx] = INF;
            ma = min(ma, dp2[xx]);
        }

        dp2[x] = min(dp2[x], ma + 1);
        dp[i] = ma + 1;
    }

    cout << dp[N - 1] << endl;
}