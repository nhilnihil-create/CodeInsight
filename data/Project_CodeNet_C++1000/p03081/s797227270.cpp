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
    int N, Q;
    V<int> s;

    cin >> N >> Q;
    {
        string in;
        cin >> in;
        rep(i, N) s.pb(in[i] - 'A');
    }

    V<int> C(Q), D(Q);

    rep(i, Q) {
        char u, v;
        cin >> u >> v;
        C[i] = (u - 'A');
        D[i] = (v == 'R');
    }

    int tol, tor;
    {
        auto ok = [&](int p) {
            rep(i, Q) {
                if (s[p] == C[i]) {
                    if (D[i]) {
                        ++p;
                    } else {
                        --p;
                    }
                }
                if (p < 0) return false;
                if (p >= N) return true;
            }
            return true;
        };

        int lo = 0, hi = N - 1;
        if (!ok(hi)) {
            puts("0");
            return 0;
        }
        if (ok(lo)) {
            hi = 0;
        }
        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (ok(m)) {
                hi = m;
            } else {
                lo = m;
            }
        }
        tol = hi;
    }

    {
        auto ok = [&](int p) {
            rep(i, Q) {
                if (s[p] == C[i]) {
                    if (D[i]) {
                        ++p;
                    } else {
                        --p;
                    }
                }
                if (p >= N) return false;
                if (p < 0) return true;
            }
            return true;
        };

        int lo = 0, hi = N - 1;
        if (!ok(lo)) {
            puts("0");
            return 0;
        }

        if (ok(hi)) {
            lo = N - 1;
        }

        while (hi - lo > 1) {
            int m = (lo + hi) / 2;
            if (ok(m)) {
                lo = m;
            } else {
                hi = m;
            }
        }
        tor = lo;
    }

    debug(tol, tor);
    cout << max(0, tor - tol + 1) << endl;

    return 0;
}
