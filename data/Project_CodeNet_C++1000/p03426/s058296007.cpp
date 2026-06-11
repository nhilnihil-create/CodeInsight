#include <bits/stdc++.h>
#define ll long long int
#define mod_ceil(a, b) (a % b) ? a / b + 1 : a / b
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll h, w, d, tmp, n;
    cin >> h >> w >> d;
    n = h * w;
    vector<pair<ll, ll>> cost(n + 10);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> tmp;
            cost[tmp] = {i, j};
        }
    }
    vector<ll> magic(n + 10, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i + d <= n)
        {
            magic[i + d] = magic[i] + abs(cost[i].first - cost[i + d].first) + abs(cost[i].second - cost[i + d].second);
        }
    }
    ll q, l, r;
    cin >> q;
    while (q--)
    {
        cin >> l >> r;
        cout << magic[r] - magic[l] << endl;
    }
}