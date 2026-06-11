#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const ll MOD = 1e9 + 7;
int N;
ll dp[(1 << 22) + 9];
int can[21][21];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> can[i][j];
        }
    }

    dp[0] = 1;
    for (int mask = 0; mask < (1 << N) - 1; mask++)
    {
        // cerr << mask << " ";
        int chlop = __builtin_popcount(mask);
        // cerr << chlop << "\n";

        for (int kobieta = 0; kobieta < N; kobieta++)
        {
            if (can[chlop][kobieta] && !(mask & (1 << kobieta)))
            {
                int mask2 = mask | (1 << kobieta);

                dp[mask2] += dp[mask];

                dp[mask2] %= MOD;
                dp[mask] += MOD;
                dp[mask2] %= MOD;
            }
        }
    }

    cout << dp[(1 << N) - 1] << "\n";
}