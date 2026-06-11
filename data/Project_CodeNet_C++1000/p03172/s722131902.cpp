#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll MOD = 1e9 + 7;
int N, K;
int a[109];
ll dp[100009], pre[100009];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> a[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= N; i++)
    {
        for (int used = K; used >= 0; used--)
        {
            int t = dp[used];

            int L = used + 1;
            int R = min(a[i] + used, K);

            pre[L] += t;
            pre[R + 1] -= t;
        }

        // for (int j = 0; j <= K; j++)
        // {
        //     cout << pre[j] << " ";
        // }
        // cout << "\n";

        ll p = 0;
        for (int j = 0; j <= K; j++)
        {
            p += pre[j];
            pre[j] = 0;

            dp[j] += p;
            dp[j] %= MOD;
            dp[j] += MOD;
            dp[j] %= MOD;
        }
    }

    cout << dp[K] << "\n";
}