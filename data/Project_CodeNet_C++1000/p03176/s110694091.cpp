#ifdef _MSC_VER
#include "stdc++.h"
#endif
#ifdef __GNUC__
#include<bits/stdc++.h>
#endif
using namespace std;

using ll = long long;

//vector
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;

//constant
const double EPS = 1e-10;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define FOR(i, s, e) for (ll i = s; i < e; i++)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(), (x).rend()

//debug
#define DUMP(x)  cerr << #x << " = " << (x) << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;

// vector
//template<typename T> vector<vector<T>> vv(ll H, ll W, T v) { return vector<vector<T>> vec(H, vector<T>(W, v)); }

// view vector
template<typename T> void view(T e) { cout << e << endl; }
template<typename T> void view(const vector<T>& v) { for (const auto& e : v) { cout << e << " "; } cout << endl; }
template<typename T> void view(const vector<vector<T> >& vv) { for (const auto& v : vv) { view(v); } }

// DP
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

template<class Monoid> struct SegTree {
    using Func = function<Monoid(Monoid, Monoid)>;
    const Func F;
    const Monoid UNITY;
    int SIZE_R;
    vector<Monoid> dat;

    SegTree(int n, const Func f, const Monoid& unity) : F(f), UNITY(unity) { init(n); }
    void init(int n) {
        SIZE_R = 1;
        while (SIZE_R < n) SIZE_R *= 2;
        dat.assign(SIZE_R * 2, UNITY);
    }

    /* set, a is 0-indexed */
    void set(int a, const Monoid& v) { dat[a + SIZE_R] = v; }
    void build() {
        for (int k = SIZE_R - 1; k > 0; --k)
            dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* update a, a is 0-indexed */
    void update(int a, const Monoid& v) {
        int k = a + SIZE_R;
        dat[k] = v;
        while (k >>= 1) dat[k] = F(dat[k * 2], dat[k * 2 + 1]);
    }

    /* get [a, b), a and b are 0-indexed */
    Monoid get(int a, int b) {
        Monoid vleft = UNITY, vright = UNITY;
        for (int left = a + SIZE_R, right = b + SIZE_R; left < right; left >>= 1, right >>= 1) {
            if (left & 1) vleft = F(vleft, dat[left++]);
            if (right & 1) vright = F(dat[--right], vright);
        }
        return F(vleft, vright);
    }
    inline Monoid operator [] (int a) { return dat[a + SIZE_R]; }

    /* debug */
    void print() {
        for (int i = 0; i < SIZE_R; ++i) {
            cout << (*this)[i];
            if (i != SIZE_R - 1) cout << ",";
        }
        cout << endl;
    }
};


int main() {

    int N;
    cin >> N;
    vi h(N);
    REP(i, N) cin >> h[i];

    SegTree<ll> st(N + 1, [](ll a, ll b) {return max(a, b); }, 0);

    ll ans = 0;
    ll a;
    REP(i, N) {
        cin >> a;
        ll A = st.get(0, h[i]);
        if (st.get(h[i], h[i] + 1) < A + a) {
            st.update(h[i], A + a);
            chmax(ans, A + a);
        }
    }

    cout << ans << endl;

#ifdef _MSC_VER
    system("PAUSE");
#endif

    return 0;
}