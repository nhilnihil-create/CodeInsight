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

vector<ll> find_all(const string str, const string subStr) {
    vector<ll> result;

    int subStrSize = subStr.size();
    int pos = str.find(subStr);

    while (pos != std::string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }

    return result;
}

int main() {
    INIT;

    ll N;
    cin >> N;
    vector<string> s(N);
    rep(i, N) cin >> s[i];

    ll ans = 0;
    vector<ll> find_vec;
    rep(i, N) {
        find_vec = find_all(s[i], "AB");
        ans += SZ(find_vec);
        find_vec.clear();
    }

    // cout << ans << endl;
    // pair<ll, ll> cnt_f, cnt_l;
    ll c1 = 0, c2 = 0, c3 = 0;
    rep(i, N) {
        ll len = SZ(s[i]);
        if (s[i][0] == 'B' && s[i][len - 1] == 'A') {
            c1++;
        } else if (s[i][0] == 'B') {
            c2++;
        } else if (s[i][len - 1] == 'A') {
            c3++;
        }
    }

    // cout << cnt_f.first << ", " <<cnt_f.second << endl;
    // cout << cnt_l.first << ", " << cnt_l.second << endl;
    if (c1 == 0) {
        ans += min(c2, c3);
    } else {
        if (c2 + c3 == 0) {
            ans += c1 - 1;
        } else {
            ans += c1 + min(c2, c3);
        }
    }

    cout << ans << endl;

    return 0;
}