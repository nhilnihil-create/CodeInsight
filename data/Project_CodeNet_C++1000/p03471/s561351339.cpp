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
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll N, Y;
    cin >> N >> Y;

    for (ll x = 0; x <= Y / 10000; x++)
    { //1万円の枚数
        for (ll y = 0; y <= Y / 5000; y++)
        { //5千円の枚数
            if ((Y - 10000 * x - 5000 * y) >= 0 && (Y - 10000 * x - 5000 * y) % 1000 == 0)
            {
                if (N == x + y + (Y - 10000 * x - 5000 * y) / 1000)
                {
                    cout << x << " " << y << " " << (Y - 10000 * x - 5000 * y) / 1000 << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}