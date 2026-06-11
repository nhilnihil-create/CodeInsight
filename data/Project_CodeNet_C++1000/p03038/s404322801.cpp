#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), s(n, 0);
    vector<pair<ll, ll>> bc(m);
    rep(i, n)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    rep(i, m)
    {
        cin >> bc[i].second >> bc[i].first;
    }
    sort(bc.begin(), bc.end());
    reverse(bc.begin(), bc.end());

    ll now = 0;
    for (int i = 0; i < m; i++)
    {
        for (ll j = now; j < min(now + bc[i].second, n); j++)
        {
            s[j] = bc[i].first;
        }
        now += bc[i].second;
        if (now >= n)
        {
            break;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += max(a[i], s[i]);
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
