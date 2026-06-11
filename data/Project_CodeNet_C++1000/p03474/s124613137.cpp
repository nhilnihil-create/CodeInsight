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
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    ll a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    bool yes = true;
    rep(i, a + b + 1) {
        if (i != a)
            if (!('0' <= s[i] && s[i] <= '9')) yes = false;
        if (s[a] != '-') yes = false;
    }

    if (yes)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}