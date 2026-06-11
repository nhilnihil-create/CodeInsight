#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)

typedef long long ll;
using namespace std;
int mod = 1000000007;

int main(void){
    string S; cin >> S;
    int N = S.length();
    vector<ll> dp(N, 0); //dp[i]: S[i]以降の部分列"BC"の数
    vector<ll> cnt_C(N, 0); //cnt_C[i]: S[i+1]~S[N-1]で'C'が出現する回数
    vector<ll> cnt_Q(N, 0);
    if(S[N-1] == 'C') cnt_C[N-2] = 1;
    else if(S[N-1] == '?') cnt_Q[N-2] = 1;
    for(int i = N-2; i >= 1; i--){
        if(S[i] == 'C'){
            cnt_C[i-1] = cnt_C[i] + 1;
            cnt_Q[i-1] = cnt_Q[i];
        }
        else if(S[i] == '?'){
            cnt_C[i-1] = cnt_C[i];
            cnt_Q[i-1] = cnt_Q[i] + 1;
        }
        else{
            cnt_C[i-1] = cnt_C[i];
            cnt_Q[i-1] = cnt_Q[i];
        }
    }

    ll ans = 0;
    ll fac3[100001];
    fac3[0] = 1;
    for(int i = 1; i <= 100000; i++) fac3[i] = (fac3[i-1]*3) % mod;

    dp[N-1] = 0;
    for(int i = N-2; i >= 0; i--){
        if(S[i] == 'A' || S[i] == 'C') dp[i] = dp[i+1];
        else if(S[i] == 'B'){
            dp[i] = (dp[i+1] + cnt_C[i]*fac3[cnt_Q[i]] + cnt_Q[i]*fac3[cnt_Q[i]-1]) % mod;
        }
        else{
            dp[i] = (dp[i+1]*3 + cnt_C[i]*fac3[cnt_Q[i]] + cnt_Q[i]*fac3[cnt_Q[i]-1]) % mod;
        }
    }
    //S[i-1]までに出てくる'?'の数を知らないときつい
    vector<ll> Q_head(N+1, 0); //Q_head[i]: S[0]が?ならQ_head[1] = 1
    for(int i = 1; i <= N; i++){
        if(S[i-1] == '?') Q_head[i] = Q_head[i-1] + 1;
        else Q_head[i] = Q_head[i-1];
    }
    for(int i = 0; i < N-2; i++) if(S[i] == 'A' || S[i] == '?') ans = (ans + (fac3[Q_head[i]]*dp[i+1] % mod)) % mod;
    cout << ans << endl;
    //rep(i, N) cout << dp[i] << " "; cout << endl;
    return 0;
}