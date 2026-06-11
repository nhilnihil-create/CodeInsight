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
#define INF (1e18)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //累積和
    vector<ll> rui(n + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        rui[i + 1] = rui[i] + a[i];
    }

    ll left = 0, right = 2;
    ll ans = INF;
    for (ll mid = 1; mid < n - 1; mid++)
    {
        //左側をしゃくとり
        ll sum1 = llabs(rui[mid] - 2 * rui[left]);
        while (left + 1 < mid && sum1 > llabs(rui[mid] - 2 * rui[left + 1]))
        {
            left++;
            sum1 = llabs(rui[mid] - 2 * rui[left]);
        }
        //右側をしゃくとり
        ll sum2 = llabs((rui[right] - rui[mid]) - (rui[n] - rui[right]));
        while (right + 1 < n && sum2 > llabs((rui[right + 1] - rui[mid]) - (rui[n] - rui[right + 1])))
        {
            right++;
            sum2 = llabs((rui[right] - rui[mid]) - (rui[n] - rui[right]));
        }
        ll mn = INF, mx = -INF;
        chmax(mx, rui[left]);
        chmax(mx, rui[mid] - rui[left]);
        chmax(mx, rui[right] - rui[mid]);
        chmax(mx, rui[n] - rui[right]);
        chmin(mn, rui[left]);
        chmin(mn, rui[mid] - rui[left]);
        chmin(mn, rui[right] - rui[mid]);
        chmin(mn, rui[n] - rui[right]);

        chmin(ans, mx - mn);
    }
    cout << ans << endl;
}