#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
//constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

//グラフ関連
struct Edge {
    ll to, cap, rev;
    Edge(ll _to, ll _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph &G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

template <typename T, typename F>
class SegmentTree {
  private:
    T e;
    F op;
    ll n;
    vector<T> dat;

  public:
    SegmentTree(F f, T _e, vector<T> v) : op(f), e(_e) {
        int _n = v.size();
        n = 1;
        while(n < _n)
            n *= 2;
        dat.resize(2 * n - 1, e);
        REP(i, _n)
        dat[n + i - 1] = v[i];
        for(int i = n - 2; i >= 0; i--)
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    SegmentTree(F f, T _e, int _n) : op(f), e(_e) {
        n = 1;
        while(n < _n)
            n *= 2;
        dat.resize(2 * n - 1, e);
        for(int i = n - 2; i >= 0; i--)
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
    void update(int i, T x) {
        i += n - 1;
        dat[i] = x;
        while(i > 0) {
            i = (i - 1) / 2;
            dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);
        }
    }
    T get(int i) {
        i += n - 1;
        return dat[i];
    }
    T query(int l, int r) {
        //[l,r)でのクエリ処理
        T left = e, right = e;
        l += n - 1;
        r += n - 1;
        while(l < r) {
            if((l & 1) == 0)
                left = op(left, dat[l]);
            if((r & 1) == 0)
                right = op(dat[r - 1], right);
            l = l / 2;
            r = (r - 1) / 2;
        }
        return op(left, right);
    }
};

void solve() {
    ll n;
    cin >> n;
    ll m = 1LL << n;
    vec<ll> a(m);
    REP(i, m) {
        cin >> a[i];
    }

    auto op = [](ll a, ll b) { return max(a, b); };
    SegmentTree<ll, decltype(op)> seg(op, -INF, m + 1);

    vec<pair<P, P>> dp(m, {{0LL, 0LL}, {0LL, 0LL}});

    auto check = [&](pair<P, P> &a, P b) {
        if(a.first < b) {
            a.second = a.first;
            a.first = b;
        } else if(a.second < b) {
            a.second = b;
        }
    };

    auto check2 = [&](pair<P, P> &a, pair<P, P> b) {
        set<P> st;
        st.insert(a.first);
        st.insert(a.second);
        st.insert(b.first);
        st.insert(b.second);
        auto it = st.end();
        it--;
        a.first = *it;
        it--;
        a.second = *it;
    };

    REP(bit, m) {
        check(dp[bit], {a[bit], (ll)bit});
        REP(i, n) {
            if(~(bit >> i) & 1) {
                check2(dp[bit | (1LL << i)], dp[bit]);
            }
        }
        if(!bit)
            continue;
        ll ans = dp[bit].first.first + dp[bit].second.first;
        chmax(ans, seg.query(0, bit));
        seg.update(bit, ans);
        cout << ans << en;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*
    ll t;
    cin >> t;
    while(t--)*/
    solve();

    return 0;
}
