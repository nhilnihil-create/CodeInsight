/**
 *
 * AtCoder Beginner Contest 101 - Problem D: Snuke Numbers (https://arc099.contest.atcoder.jp/tasks/arc099_b)
 *
 * Process a string of symbols '+' and '-' and find the result.
 *
 * Ad-Hoc solution: sum +1 for each '+', subtract one for each '-', starting from zero.
 */
#include <iostream>
#include <vector>

#define LOG(var, sep) (cerr << #var << " = " << (var) << (sep))
#define LOGM(msg) (cerr << (msg))
#define LOGV(vec, sep) { cerr << #vec << " ="; for (const auto& v : vec) cerr << " " << v; cerr << (sep); }
#define LOGA(arr, N, sep) { cerr << #arr << " ="; for (int i = 0; i < N; ++i) cerr << " " << (arr)[i]; cerr << (sep); }
#define LOGA2(arr, N, M, sep) { cerr << #arr << " =\n"; for (int i = 0; i < N; ++i) { for (int j = 0; j < M; ++j) cerr << (arr)[i][j] << " "; cerr << endl; } cerr << (sep); }


using namespace std;
using ll = long long;

ll S(ll N)
{
    ll ans = 0;

    while (N)
    {
        ans += (N % 10);
        N /= 10;
    }

    return ans;
}

ll f(ll N)
{
    if (N == 1)
        return 1;

    vector<ll> cs;
    cs.push_back(N);
 
    ll x = N, y = N, base = 1;

    while (y)
    {
        auto d = y % 10;
        y /= 10;

        for (int i = d + 1; i <= 9; ++i)
        {
            x += base;
            cs.push_back(x);
        }

        base *= 10;
    }

    auto ans = N, s = S(N);

    for (const auto& c : cs)
    {
/*if (N == 10)
{
    auto a = 1.0 * N/S(N);
    auto b = 1.0 * c/S(c);
    LOG(c, ' '); LOG(S(c), ' '); LOG(a
}*/
        if (c * s < ans * S(c))
        {
            ans = c;
            s = S(c);
        }
    }
    
    return ans;
}

void solve(ll K)
{
    ll x = 1;

    while (K--)
    {
        cout << x << endl;
        x = f(x + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    ll K;
    cin >> K;

    solve(K);

    return 0;
}
