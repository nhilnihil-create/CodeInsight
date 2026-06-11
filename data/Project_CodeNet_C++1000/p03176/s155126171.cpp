#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <cmath>
#include <iomanip>

#define vec vector

using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;
using vvl = vector<vl>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using ld = long double;

int n;
vl a, h, dp_stree;

ll query(int l, int r)
{
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, dp_stree[l++]);
        if (r & 1)
            res = max(res, dp_stree[--r]);
    }
    return res;
}

void update(int p, ll v)
{
    for (dp_stree[p += n] = v; p > 1; p >>= 1)
        dp_stree[p >> 1] = max(dp_stree[p], dp_stree[p ^ 1]);
}

int main()
{
    cin >> n;
    h = vl(n);
    a = vl(n);
    for (auto &e : h)
        cin >> e;
    for (auto &e : a)
        cin >> e;
    dp_stree = vl(2 * (n + 1), 0);
    for (int i = 0; i < n; i++)
    {
        ll m = query(1, h[i]);
        if (m + a[i] > query(h[i], h[i] + 1))
            update(h[i], m + a[i]);
    }
    cout << query(1, n + 1);
    return 0;
}