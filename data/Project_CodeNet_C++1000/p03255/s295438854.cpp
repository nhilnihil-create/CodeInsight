#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
typedef unsigned long long ll;

ll E(ll i, ll x)
{
    if (i == 1)
    {
        return 5 * x;
    }
    return (2 * i + 1) * x;
}

int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N);
    for (ll i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    sort(x.begin(), x.end(), std::greater<ll>());
    for (ll i = 1; i < x.size(); i++)
    {
        x[i] += x[i - 1];
    }
    x.insert(x.begin(), 0);
    ll energy = LLONG_MAX;
    for (ll k = 1; k <= N; k++)
    {
        ll cost = (N + k) * X;
        for (ll i = 1; i <= N; i++)
        {
            if (i * k <= N)
            {
                cost += E(i, x[i * k] - x[(i - 1) * k]);
            }
            else
            {
                cost += E(i, x.back() - x[(i - 1) * k]);
                break;
            }
        }
        if (cost < energy)
        {
            energy = cost;
        }
    }
    cout << energy << endl;
    return 0;
}