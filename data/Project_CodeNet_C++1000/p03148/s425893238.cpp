#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define RREP(i, n) for (int i = (n); i >= 0; i--)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int INF = 200000000;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T> vector<T> make_vec(size_t a) { return vector<T>(a); }
template <class T, class... Ts> auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;

    vector<vector<ll>> item(n);
    REP(i, n) {
        ll kind, value;
        cin >> kind >> value;
        --kind;
        item[kind].push_back(value);
    }
    vector<ll> y0, y1;
    REP(i, n) {
        if (item[i].size() == 0)
            continue;
        sort(ALL(item[i]));
        y1.push_back(item[i].back());
        item[i].pop_back();
        y0.insert(y0.end(), item[i].begin(), item[i].end()); // まとめてinsert
    }
    sort(ALL(y1), greater<ll>());
    sort(ALL(y0), greater<ll>());

    ll Y = max(1LL, k - ll(y0.size())); // はじめの 1 の数(なるべく0が多くなるように = 1が少なくなるように)

    ll X = 0;
    REP(i, Y) { X += y1[i]; }
    REP(i, k - Y) { X += y0[i]; }
    ll ans = 0;
    while (1) {
        ans = max(ans, X + Y * Y);
        if (Y >= k || Y >= y1.size())
            break;
        X += y1[Y];
        X -= y0[k - Y - 1];
        Y++;
    }

    cout << ans << endl;

    return 0;
}
