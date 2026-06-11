#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return 1;
    }
    return 0;
}

int main()
{
    ll n;
    cin >> n;
    vector<pair<P, ll>> height;

    ll index;
    rep(i, n)
    {
        ll x, y, h;
        cin >> x >> y >> h;
        height.push_back({{x, y}, h});

        if (h != 0)
            index = (ll)(height.size() - 1);
    }

    //(cx,cy) 全探索
    rep(cx, 101)
    {
        rep(cy, 101)
        {
            bool center = true;
            ll H = height[index].se + abs(height[index].fi.fi - cx) + abs(height[index].fi.se - cy);

            //(cx,cy)が全部の与えられた点を満たすか
            rep(i, n)
            {
                ll num = max(0ll, H - abs(height[i].fi.fi - cx) - abs(height[i].fi.se - cy));

                if (num != height[i].se)
                    center = false;
            }

            if (center)
            {
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }

    return 0;
}