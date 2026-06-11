#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
const long long INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    int v[n], c[n];
    int ans = 0;
    rep(i, n) cin >> v[i];
    rep(i, n) cin >> c[i];
    rep(i, n)
    {
        ans += v[i] > c[i] ? v[i] - c[i] : 0;
    }
    cout << ans << endl;

    return 0;
}
