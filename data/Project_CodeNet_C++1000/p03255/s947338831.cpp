#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N);
    for (int i = 0; i < N; i++)
    {
        cin >> x[i];
    }
    reverse(x.begin(), x.end());
    vector<ll> xsum(N);
    xsum[0] = x[0];
    for (int i = 1; i < N; i++)
    {
        xsum[i] += xsum[i - 1] + x[i];
    }
    ll energy = 9223372036854775807;
    for (int i = 1; i <= N; i++)
    {
        ll cost = (i + N) * X;
        cost += 5 * xsum[i - 1];
        ll num = 2 * i - 1;
        ll cnt = 1;
        while (num < N)
        {
            cost += (2 * cnt + 3) * (xsum[num] - xsum[num - i]);
            cnt++;
            num += i;
        }
        cost += (2 * cnt + 3) * (xsum[N - 1] - xsum[num - i]);
        energy = min(energy, cost);
    }
    cout << energy << endl;
    return 0;
}