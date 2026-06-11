#include <bits/stdc++.h>
#define LOOP(n) for (int _i = 0; _i < (n); _i++)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define RREP(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, r, n) for (int i = (r); i < (n); ++i)
#define ALL(obj) begin(obj), end(obj)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;

const int INF = 2100100100;
const int MOD = 1e9 + 7;

// 多次元 vector 生成
template <class T>
vector<T> make_vec(size_t a) {
    return vector<T>(a);
}
template <class T, class... Ts>
auto make_vec(size_t a, Ts... ts) {
    return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));
}
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

int N, M, K, Q, W, H, R, C;
string S;

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);

    cin >> N >> K;
    vector<P> p(N);
    REP(i, N) {
        ll x, y;
        cin >> x >> y;
        p[i] = make_pair(x, y);
    }
    sort(ALL(p));
    ll ans = 4e18;
    REP(i, N) {
        FOR(j, i + 1, N) {
            FOR(k, i, j + 1) {
                ll x1 = p[i].first;
                ll x2 = p[j].first;
                ll y1 = p[k].second;
                ll num = 0;
                vector<ll> y2;
                FOR(l, i, j + 1) {
                    if (y1 <= p[l].second) {
                        num++;
                        y2.push_back(p[l].second);
                    }
                }
                if ((int)y2.size() >= K) {
                    sort(ALL(y2));
                    chmin(ans, abs(x2 - x1) * abs(y2[K - 1] - y1));
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
