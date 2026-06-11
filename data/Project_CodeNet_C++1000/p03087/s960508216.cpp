#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <deque>
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
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<ll> l(Q), r(Q);
    rep(i, Q) cin >> l[i] >> r[i];

    vector<ll> find_vec = find_all(S, "AC");
    // repv(find_vec) { cout << *it << " "; }
    // cout << endl;

    rep(i, Q) {
        l[i]--;
        r[i]--;

        ll lpos = lower_bound(ALL(find_vec), l[i]) - find_vec.begin();
        ll rpos = lower_bound(ALL(find_vec), r[i]) - find_vec.begin();
        cout << rpos - lpos << endl;
    }

    return 0;
}