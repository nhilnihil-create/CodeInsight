#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)
int cum_w[2 * pow10(5)];

void solve()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    REP0 (i, N)
    {
        cum_w[i] = (S[i] == '.');
        if (i != 0)
            cum_w[i] += cum_w[i - 1];
        // cout << cum_w[i] << endl;
    }

    // 全部 blackに変える
    int ans = cum_w[N - 1];

    // i番目までを white にする
    REP0 (i, N)
    {
        int to_w = (i + 1) - cum_w[i];
        int to_b = cum_w[N - 1] - cum_w[i];
        ans = min(ans, to_w + to_b);
    }
    cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
