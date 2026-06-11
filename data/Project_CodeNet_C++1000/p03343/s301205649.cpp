#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (int i = m; i < (n); i++)
#define ALL(c) (c).begin(), (c).end()

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }

template <class T, class U>
void chmin(T& t, const U& u) {
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
    if (t < u) t = u;
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    os << "(" << p.first << "," << p.second << ")";
    return os;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "{";
    rep(i, v.size()) {
        if (i) os << ",";
        os << v[i];
    }
    os << "}";
    return os;
}

#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define debug(...) (void(0))
#define dump(x) (void(0))
#endif

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    V<int> A(N);
    rep(i, N) cin >> A[i];

    int ans = TEN(9) + 10;

    rep(i, N) {
        int mi = A[i];
        VV<int> vec;
        {
            V<int> cur;
            rep(j, N) {
                if (A[j] < mi) {
                    vec.pb(cur);
                    cur.clear();
                } else {
                    cur.pb(A[j]);
                }
            }
            vec.pb(cur);
        }
        V<int> cand;
        for (auto& v : vec) {
            sort(ALL(v));
            int sz = v.size();
            rep(j, sz - K + 1) { cand.pb(v[j]); }
        }
        sort(ALL(cand));
        if (cand.size() >= Q) {
            chmin(ans, cand[Q - 1] - cand[0]);
        }
    }
    cout << ans << endl;

    return 0;
}