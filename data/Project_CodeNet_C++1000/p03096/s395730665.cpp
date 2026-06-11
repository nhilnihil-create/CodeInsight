#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}
long long fast_exp(long long base, long long exp, long long mod = MOD) {
    long long tot = 1;
    for(;exp > 0;exp >>= 1) {
       if((exp & 1) == 1) tot = tot * base % mod;
       base = base * base % mod;
    }
    return tot;
}
long long slow_mult(long long base, long long exp, long long mod = MOD) {
    long long tot = 0;
    for(;exp > 0;exp >>= 1){
       if((exp & 1) == 1) tot = (tot + base) % mod;
       base = base * 2 % mod;
    }
    return tot;
}

long long dp[200005], arr[200005];

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n; cin >> n;

    long long cur, tot = 0, prev = 0;

    dp[0] = 1;

    // maybe optimize to colours :ooo

    for(int i = 1; i <= n; ++i){

        cin >> cur;

        if(cur == prev) continue;

        dp[cur] += dp[prev];
        dp[cur] %= MOD;

        prev = cur;

    }

    cout << dp[prev];

    return 0;

}
