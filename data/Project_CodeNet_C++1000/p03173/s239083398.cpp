#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll max_N = 400 + 50, INF = 1e15, MOD = 1e9 + 7;
ll N, arr[max_N], DP[max_N][max_N], presum[max_N];

ll min_cost_combine(ll s, ll e)
{
    if (s == e)
        return 0;
    ll &res = DP[s][e];
    if (res != -1)
        return res;
    res = INF;
    for (int i = s; i < e; ++i)
        res = min(res, presum[e] - presum[s-1] + min_cost_combine(s, i) + min_cost_combine(i + 1, e));
    return res;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; ++i)
        cin >> arr[i];
    presum[0] = 0;
    for (int i = 1; i <= N; ++i)
        presum[i] = presum[i - 1] + arr[i];
    memset(DP, -1, sizeof(DP));
    cout << min_cost_combine(1, N) << "\n";
    return 0;
}