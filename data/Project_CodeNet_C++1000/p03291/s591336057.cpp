#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(long long i=0; i<(n); i++)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main(){
    string s, t; cin>>s;
    ll n = s.size();
    vector<ll> cnt(n+1, 0);
    ll q=0;
    ll res = 0;
    ll mod = 1e9+7;
    rep(i, n){
        cnt[i+1] = cnt[i];
        if(s[i] == '?'){
            cnt[i+1]++;
            q++;
            continue;
        }
        t.push_back(s[i]);
    }
    if(q>=3){
        ll tmp = q*(q-1)*(q-2)/6;
        tmp %= mod;
        tmp *= modpow(3, q-3, mod);
        res += tmp;
        res %= mod;
    }
    rep(i, n){
        if(s[i]=='A'){
            res += (q-cnt[i+1])*(q-cnt[i+1]-1)/2 * modpow(3, q-2, mod);
        }else if(s[i]=='B'){
            res += cnt[i+1] * (q-cnt[i+1]) * modpow(3, q-2, mod);
        }else if(s[i]=='C'){
            res += cnt[i+1] * (cnt[i+1] - 1) /2 * modpow(3, q-2, mod);
        }
        res %= mod;
    }
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));

    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    rep(i, n){
        dp[i+1] = dp[i];
        if(s[i] == 'A') dp[i+1][0]++;
        else if(s[i]=='B') dp[i+1][1] += dp[i][0];
        else if(s[i]=='C') dp[i+1][2] += dp[i][1];
        dp[i+1][0]%=mod;
        dp[i+1][1]%=mod;
        dp[i+1][2]%=mod;
    }
    res += dp[n][2] * modpow(3, q, mod);
    res %= mod;

    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    rep(i, n){
        dp[i+1] = dp[i];
        if(s[i] == 'A') dp[i+1][0]++;
        else if(s[i]=='B') dp[i+1][1] += dp[i][0];
        else if(s[i]=='?') dp[i+1][2] += dp[i][1];
        dp[i+1][0]%=mod;
        dp[i+1][1]%=mod;
        dp[i+1][2]%=mod;
    }
    res += dp[n][2] * modpow(3, q-1, mod);
    res %= mod;

    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    rep(i, n){
        dp[i+1] = dp[i];
        if(s[i] == 'A') dp[i+1][0]++;
        else if(s[i]=='?') dp[i+1][1] += dp[i][0];
        else if(s[i]=='C') dp[i+1][2] += dp[i][1];
        dp[i+1][0]%=mod;
        dp[i+1][1]%=mod;
        dp[i+1][2]%=mod;
    }
    res += dp[n][2] * modpow(3, q-1, mod);
    res %= mod;

    dp[0][0] = 0; dp[0][1] = 0; dp[0][2] = 0;
    rep(i, n){
        dp[i+1] = dp[i];
        if(s[i] == '?') dp[i+1][0]++;
        else if(s[i]=='B') dp[i+1][1] += dp[i][0];
        else if(s[i]=='C') dp[i+1][2] += dp[i][1];
        dp[i+1][0]%=mod;
        dp[i+1][1]%=mod;
        dp[i+1][2]%=mod;
    }
    res += dp[n][2] * modpow(3, q-1, mod);
    res %= mod;

    cout << res << endl;

    return 0;
}