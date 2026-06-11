#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;

const ll MAX = 2000 * 2000 + 1;
ll dp[MAX + 1];

int main() {
    int N;
    cin >> N;

    vector<ll> A(N);
    ll Sum = 0;
    for (int i = 0; i < N; ++i) cin >> A[i], Sum += A[i];

    bitset<MAX> dp(1);
    for (int i = 0; i < N; ++i)
        dp |= dp << A[i];

    ll ans = (Sum + 1) / 2;
    for (; ans < MAX; ++ans)
        if (dp[ans]) break;

    cout << ans << endl;
}