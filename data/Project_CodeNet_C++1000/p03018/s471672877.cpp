#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;
typedef long long ll;

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define reps(i, f, n) for (ll i = (f); i < (n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define repv(v) for (auto it = (v).begin(); it != (v).end(); it++)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define INIT    \
    cin.tie(0); \
    ios::sync_with_stdio(false);

template <class T>
inline bool chmax(T& a, T b) {
    return a = (a < b) ? b : a;
}
template <class T>
inline bool chmin(T& a, T b) {
    return a = (a > b) ? b : a;
}

ll const INF = 1LL << 60;
ll const MOD = 1000000007;

int main() {
    INIT;
    string s;
    cin >> s;

    ll ans = 0;
    ll start = 0;

    rep(i, SZ(s) - 2) {
        if (s[i] != 'A') start = i + 1;

        char c1 = s[i];
        char c2 = s[i + 1];
        char c3 = s[i + 2];

        if (c1 == 'A' && c2 == 'B' && c3 == 'C') {
            ans += i - start + 1;
            s[start] = 'B';
            s[start + 1] = 'C';

            ll cnt = 0;
            for (ll j = i + 2; j >= start + 2; j--) {
                s[j] = 'A';
                cnt++;
                if (cnt >= 3) break;
            }

            start += 2;
        }
    }

    cout << ans << endl;

    return 0;
}