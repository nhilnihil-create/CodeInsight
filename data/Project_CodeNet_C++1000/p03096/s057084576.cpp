#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD = 1e9 + 7;

int main() {
    int N; cin >> N;
    vector<int> C(1);
    cin >> C[0];
    for (int i = 1; i < N; i++) {
        int c; cin >> c;
        if (C[C.size()-1] != c) C.push_back(c);
    }
    N = C.size();
    map<ll, ll> cnt;
    vector<ll> dp(N+1); dp[0] = 1;
    for (int i = 1; i < N+1; i++) {
        dp[i] = dp[i-1] + cnt[C[i-1]];
        dp[i] %= MOD;
        cnt[C[i-1]] = dp[i];
    }

    cout << dp[N] % MOD << endl;
}
