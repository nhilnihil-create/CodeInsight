#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;
const int inf = (1 << 30);
typedef long long ll;
const ll maxn = 1e5 + 5;
vector<ll> vec;
ll n, sum[maxn * 10], c[maxn * 10], a[maxn];
ll lowbit(ll x)
{
    return x & (-x);
}
void modify(ll i)
{
    while (i <= 2 * maxn)
    {
        ++c[i];
        i += lowbit(i);
    }
}
ll getsum(ll i)
{
    ll res = 0;
    while (i > 0)
    {
        res += c[i];
        i -= lowbit(i);
    }
    return res;
}
bool check(ll mid)
{
    memset(c, 0, sizeof c);
    for (ll i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + (a[i] >= mid ? 1 : -1);
    ll res = 0;
    for (ll i = 0; i <= n; i++)
    {
        res += getsum(sum[i] + maxn);
        modify(sum[i] + maxn);
    }
    if (res >= ((n + 1) * n / 4))
        return true;
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll l = 0, r = 0;
    cin >> n;
    for (ll i = 1; i <= n; i++)
        cin >> a[i], r = max(r, a[i]);
    ll ans = 0;
    while (l <= r)
    {
        ll mid = l + r >> 1;
        if (check(mid))
            l = mid + 1, ans = mid;
        else
            r = mid - 1;
    }
    cout << ans << endl;
}
