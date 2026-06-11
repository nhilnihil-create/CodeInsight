#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;

signed main()
{
    int n;
    cin >> n;
    vi a(n);
    vi b(n);
    rep(i, n)
    {
        cin >> a[i];
    }
    rep(i, n)
    {
        cin >> b[i];
    }
    ll ans = 0;
    ll rest = 0;
    priority_queue<int> pq;
    rep(i, n)
    {
        if (a[i] < b[i])
        {
            ans++;
            rest += b[i] - a[i];
        }
        else
        {
            pq.push(a[i] - b[i]);
        }
    }
    while (rest > 0)
    {
        if (pq.size() == 0)
        {
            cout << -1 << endl;
            return 0;
        }
        int d = pq.top();
        pq.pop();
        rest -= d;
        ans++;
    }
    cout << ans << endl;
    return 0;
}