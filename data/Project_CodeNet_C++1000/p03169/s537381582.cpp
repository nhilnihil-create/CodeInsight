#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll max_N = 3e2 + 5, INF = 1e15, MOD = 1e9 + 7;
ll N;
ld DP[max_N][max_N][max_N];

ld expected_turns(ll cnt1, ll cnt2, ll cnt3)
{
    ll cnt0 = N - cnt1 - cnt2 - cnt3;
    if (cnt0 == N)
        return 0;
    if (cnt1 < 0 || cnt2 < 0 || cnt3 < 0 || cnt0 < 0)
        return 0;
    ld &res = DP[cnt1][cnt2][cnt3];
    if (res != ld(-1))
        return res;
    res = (N + cnt1 * expected_turns(cnt1 - 1, cnt2, cnt3) + cnt2 * expected_turns(cnt1 + 1, cnt2 - 1, cnt3) + cnt3 * expected_turns(cnt1, cnt2 + 1, cnt3 - 1));
    res = res / (N - cnt0);
    return res;
}

int main()
{
    cin >> N;
    ll cnt1, cnt2, cnt3, x;
    cnt1 = cnt2 = cnt3 = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> x;
        if (!x)
            continue;
        if (x == 1)
            ++cnt1;
        else if (x == 2)
            ++cnt2;
        else
            ++cnt3;
    }
    for (int i = 0; i < max_N; ++i)
        for (int j = 0; j < max_N; ++j)
            fill(DP[i][j], DP[i][j] + max_N, ld(-1));
    cout << fixed << setprecision(9) << expected_turns(cnt1, cnt2, cnt3) << "\n";
    return 0;
}