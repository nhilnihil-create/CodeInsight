#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define LLINF (1e18)
#define PI (acos(-1))
#define MOD (1000000007)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> rui(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        rui[i + 1] = rui[i] + a[i];
    }
    vector<ll> kouho;
    for (ll i = 0; i <= n; i++)
    {
        for (ll j = i + 1; j <= n; j++)
        {
            kouho.push_back(rui[j] - rui[i]);
        }
    }
    sort(RALL(kouho));
    vector<ll> now = kouho;
    for (ll i = 63; i >= 0; i--)
    {
        vector<ll> next;
        for (ll j = 0; j < (ll)now.size(); j++)
        {
            if (now[j] & (1LL << i))
            {
                next.push_back(now[j]);
            }
        }
        if ((ll)next.size() >= k)
        {
            now = next;
        }
    }
    ll ans;
    for (ll i = 0; i < k; i++)
    {
        i == 0 ? ans = now[i] : ans &= now[i];
    }
    cout << ans << endl;
}
