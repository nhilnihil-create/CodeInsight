#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main()
{
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << x2 - y2 + y1 << " " << y2 + x2 - x1 << " ";
    cout << x1 - y2 + y1 << " " << y1 + x2 - x1 << endl;
    return 0;
}