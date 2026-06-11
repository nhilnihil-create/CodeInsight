#include <bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
using namespace std;
// namespace boost::multiprecision;
// using Bint = cpp_int;
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for(int i = int(a), i##_len = (b); i < i##_len; ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define _repr(i, n) repri(i, n, 0)
#define repri(i, a, b) for(int i = int(a), i##_len = (b); i >= i##_len; --i)
/* 閉区間で定義しているので注意！repr(i,n,m)でn〜mまで */
#define repr(...) _overload3(__VA_ARGS__, repri, _repr, )(__VA_ARGS__)
/* 逆回しのループ。両閉区間であることに注意 */
#define all(x) (x).begin(), (x).end()
#define debug(x) cerr << #x << ": " << (x) << '\n'
typedef long long lint;
using Int = long long;
#define int lint
#define endl '\n'
const int INF = (int)1145141919;
int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
const lint LINF = (lint)1e18;
typedef vector<int> vint;
typedef pair<int, int> pint;
template <class T> bool chmax(T &a, const T &b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> bool chmin(T &a, const T &b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T, class U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << p.first << " " << p.second;
    return os;
}

template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}

template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? ", " : "");
    }
    os << "]";
    return os;
}

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
    for(T &in : v)
        is >> in;
    return is;
}

template <typename T = lint> vector<T> make_v(size_t a) { return vector<T>(a); }

template <typename T, typename... Ts> auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template <typename T, typename V>
typename enable_if<is_class<T>::value == 0>::type fill_v(T &t, const V &v) {
    t = v;
}

template <typename T, typename V>
typename enable_if<is_class<T>::value != 0>::type fill_v(T &t, const V &v) {
    for(auto &e : t)
        fill_v(e, v);
}

// BEGIN CUT HERE
template <typename T>
vector<T> dijkstra(int s, vector<vector<pair<int, T>>> &G) {
    const T INF = numeric_limits<T>::max();
    using P = pair<T, int>;
    int n = G.size();
    vector<T> d(n, INF);
    vector<int> b(n, -1);
    priority_queue<P, vector<P>, greater<P>> q;
    d[s] = 0;
    q.emplace(d[s], s);
    while(!q.empty()) {
        P p = q.top();
        q.pop();
        int v = p.second;
        if(d[v] < p.first)
            continue;
        for(auto &e : G[v]) {
            int u = e.first;
            T c = e.second;
            if(d[u] > d[v] + c) {
                d[u] = d[v] + c;
                b[u] = v;
                q.emplace(d[u], u);
            }
        }
    }
    return d;
}
// END CUT HERE

/* templates */ /* templates */ /* templates */ /* templates */ /* templates */
/* make directory: atcoder-tools gen コンテスト略称(ex.agc033) */
/* テストコード：atcoder-tools test */
/* 提出：atcoder-tools submit -u */

signed main() {
#ifdef LOCAL
    ifstream in("in_2.txt");
    cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif

    /* input part */
    long long K;
    cin >> K;

    /* write your code!*/
    vector<vector<pint>> G(K);
    rep(i, K) {
        G[i].emplace_back((i + 1) % K, 1);
        G[i].emplace_back((i * 10) % K, 0);
    }
    cout << dijkstra(1, G)[0] + 1 << endl;
}
