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
inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <typename T>
inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int main() {
    string s;
    cin >> s;

    if (s == "zyxwvutsrqponmlkjihgfedcba") {
        cout << -1 << endl;
        return 0;
    }
    vector<ll> snum(s.size());
    vector<bool> check(26, false);
    rep(i, s.size()) { snum[i] = (ll)(s[i] - 'a'); }

    rep(i, s.size()) { check[(ll)(s[i] - 'a')] = true; }

    bool all = true;
    ll key = -1;
    rep(i, 26) {
        if (check[i] == false) {
            all = false;
            key = i;
            break;
        }
    }

    if (key != -1) {
        cout << s << (char)('a' + key) << endl;
    } else {
        rep(i, 26) snum.push_back(-1ll);
        while (next_permutation(snum.begin(), snum.end())) {
            vector<ll> ins = snum;
            sort(ins.begin(), ins.end());
            bool B = true;
            rep(i, ins.size() - 1) {
                if (ins[i] == ins[i + 1]) B = false;
            }

            break;
        }

        rep(i, s.size()) {
            if (snum[i] != -1) cout << (char)('a' + snum[i]);
        }
        cout << endl;
    }

    return 0;
}