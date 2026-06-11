#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1 << 18; // 2.6e5
const int N = 200005;
ll seg[2 * MAXN]; // root is seg[1]

ll n, a[N], h[N];

void build()
{
    for (int i = N - 1; i >= 0; i--)
        seg[i] = max(seg[i << 1], seg[i << 1 | 1]);
}

void update(int p, ll val)
{
    for (seg[p += N] = val; p > 0; p >>= 1)
        seg[p >> 1] = max(seg[p], seg[p ^ 1]);
}

ll query(int l, int r) // [l, r]
{
    ll res = -1e9;
    for (l += N, r += N; l <= r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, seg[l++]);
        if (!(r & 1))
            res = max(res, seg[r--]);
    }
    return res;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
    {
        ll val = query(0, h[i]);
        update(h[i], val + a[i]);
    }

    cout << query(0, N) << endl;
}