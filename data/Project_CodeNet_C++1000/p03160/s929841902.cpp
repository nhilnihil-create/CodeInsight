#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 510000;
const int MOD = 1000000007;

/*long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}*/
int main() {
    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    int dp[1000000];

    for (int i = 0; i < 1000000; i++)
    {
        dp[i] = 0;
    }
    dp[2] = abs(h[1] - h[0]);
    for (int i = 3; i <= N; i++)
    {
        dp[i] = min(dp[i - 1] + abs(h[i - 2] - h[i - 1]), dp[i - 2] + abs(h[i - 3] - h[i - 1]));
    }
    cout << dp[N] << endl;
    return 0;
}