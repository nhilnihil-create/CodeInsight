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
    string S;
    cin >> S;
    if (S.size() < 7) {
        cout << "NO\n";
        return 0;
    }

    bool ans = false;
    string key = "keyence";
    // if (S.substr(0, 7) == key) ans = true;
    // if (S.substr(S.size() - 7) == key) ans = true;

    rep(i, 7 + 1) {
        // if (i == 0 || i == 7) continue;
        string sp = key.substr(0, i), ano = key.substr(i);

        // cout << sp << " " << ano << "\n";

        if (S.substr(0, i) == sp && S.substr(S.size() - 7 + i) == ano) {
            ans = true;
        }
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}