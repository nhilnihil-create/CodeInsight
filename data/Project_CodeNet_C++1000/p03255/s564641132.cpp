#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <iomanip>
#include <numeric>
#include <climits>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
#define SORT(c) sort((c).begin(), (c).end())
#define INF 1e18
#define MOD 1e9 + 7

typedef unsigned long long ll;
typedef pair<int, int> P;
typedef vector<int> V;
typedef map<int, int> M;

ll div_up(ll a, ll b)
{
    return (a + b - 1) / b;
}

int main()
{

    ll N, X, x[212345], sum[212345];
    cin >> N >> X;

    sum[0] = 0;
    for (ll i = 0; i < N; i++)
    {
        cin >> x[i];
        sum[i + 1] = sum[i] + x[i];
    }

    ll res = 1e18 * 18;

    for (ll k = 1; k <= N; k++)
    {
        ll tmp = 0;

        ll a = 5;

        for (ll i = 0; i < div_up(N, k); i++)
        {
            if (N >= k * (i + 1))
                tmp += a * (sum[N - k * i] - sum[N - k * (i + 1)]);
            else
                tmp += a * sum[N - k * i];

            if (i > 0)
                a += 2;
        }

        tmp += k * X;

        res = min(res, tmp);
    }

    res += N * X;

    cout << res << endl;

    return 0;
}
