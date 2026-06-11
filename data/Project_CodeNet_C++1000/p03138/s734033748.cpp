#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
#define pow10(n) int(1e##n + n)
int N;
LL K;
LL A[pow10(5)];
LL d[63];
LL opt[63];
LL ans;
LL D_MAX = 42;
// 桁DP 上位桁から
LL dp[100][2];

void solve()
{
    cin >> N >> K;
    REP0 (i, N)
    {
        cin >> A[i];

        for (LL j = D_MAX; j >= 0; j--)
        {
            if (A[i] & (1LL << j))
            {
                d[j]++;
            }
        }

        ans += A[i];
    }

    for (LL j = D_MAX; j >= 0; j--)
    {
        if (0 < N - 2 * d[j])
            opt[j] = (N - 2 * d[j]) * (1LL << j);
    }

    LL max_inc = 0;

    for (LL j = D_MAX; j >= 0; j--)
    {
        if (K & (1LL << j))
        {
            dp[j][0] = dp[j + 1][0] + opt[j];
            // j 桁目で未満を確定させること = j桁目でK=1のとき0を選ぶこと
            // そして 0~j-1桁目は最適に選べる
            dp[j][1] = dp[j + 1][0];
            REP0 (i, j)
            {
                dp[j][1] += opt[i];
            }
            max_inc = max(max_inc, dp[j][0]);
            max_inc = max(max_inc, dp[j][1]);
        }
        else
        {
            dp[j][0] = dp[j + 1][0];
        }
    }

    cout << ans + max_inc << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    solve();
    return 0;
}
