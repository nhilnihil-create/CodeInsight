#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using Pld = pair<ld, ld>;
using Vec = vector<ll>;
using VecP = vector<P>;
using VecB = vector<bool>;
using VecC = vector<char>;
using VecD = vector<ld>;
using VecS = vector<string>;
template <class T>
using Vec2 = vector<vector<T>>;
#define REP(i, m, n) for(ll i = (m); i < (n); ++i)
#define REPN(i, m, n) for(ll i = (m); i <= (n); ++i)
#define REPR(i, m, n) for(ll i = (m)-1; i >= (n); --i)
#define REPNR(i, m, n) for(ll i = (m); i >= (n); --i)
#define rep(i, n) REP(i, 0, n)
#define repn(i, n) REPN(i, 1, n)
#define repr(i, n) REPR(i, n, 0)
#define repnr(i, n) REPNR(i, n, 1)
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define fs first
#define sc second
template <class T1, class T2>
bool chmax(T1 &a, const T2 b){if(a < b){a = b; return true;} return false;}
template <class T1, class T2>
bool chmin(T1 &a, const T2 b){if(a > b){a = b; return true;} return false;}
ll pow2(const int n){return (1LL << n);}
template <class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (const T &i : v) os << i << ' ';
    return os;
}
void co() { cout << '\n'; }
template <class Head, class... Tail>
void co(Head&& head, Tail&&... tail) {
    cout << head << ' ';
    co(forward<Tail>(tail)...);
}
void ce() { cerr << '\n'; }
template <class Head, class... Tail>
void ce(Head&& head, Tail&&... tail) {
    cerr << head << ' ';
    ce(forward<Tail>(tail)...);
}
void sonic(){ios::sync_with_stdio(false); cin.tie(0);}
void setp(const int n){cout << fixed << setprecision(n);}
constexpr int INF = 1000000001;
constexpr ll LINF = 1000000000000000001;
constexpr ll MOD = 1000000007;
constexpr ll MOD_N = 998244353;
constexpr ld EPS = 1e-11;
const double PI = acos(-1);

template <class T>
struct BIT {
    ll N;
    vector<T> data;

    BIT(int64_t n) {
        init(n);
    }

    void init(int64_t n) {
        N = 1;
        while (N <= n) N <<= 1;
        data.assign(N, 0);
    }

    void build(vector<T> v) {
        data.assign(N, 0);
        for (size_t i = 0; i < v.size(); ++i) {
            if (i == 0) trans(i, v[i]);
            else trans(i, v[i] - v[i - 1]);
        }
        trans(v.size(), -v.back());
    }

    void trans(int64_t k, T x) {
        ++k;
        while (k <= N) {
            data[k] += x;
            k += k & -k;
        }
    }

    void update(int64_t k, T x) { add(k, k + 1, x - at(k)); }

    void add(int64_t k, T x) { add(k, k + 1, x); }
    void add(int64_t a, int64_t b, T x) {
        trans(a, x);
        trans(b, -x);
    }

    T at(int64_t k) {
        ++k;
        T res = 0;
        while (k > 0) {
            res += data[k];
            k -= k & -k;
        }
        return res;
    }
};

int main(void) {
    ll n;
    cin >> n;
    Vec a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) chmin(a[i], 3e5);

    ll l = 0, r = 3e5;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        BIT<ll> bit(3e5);
        ll len = 0;
        rep(i, n){
            if (a[i] > len) {
                len = a[i];
                continue;
            }
            len = a[i];
            if (a[i] == 3e5) continue;
            if (bit.at(a[i]) < 0) bit.update(a[i], 0);
            bit.add(a[i], 1);
            bit.add(a[i] + 1, 3e5, -INF);
            ll p = a[i];
            while(p >= 1 && bit.at(p) >= m){
                bit.update(p, 0);
                --p;
                if (bit.at(p) < 0) bit.update(p, 0);
                bit.add(p, 1);
            }
            if(bit.at(0) != 0) break;
        }

        if (bit.at(0) == 0) r = m;
        else
            l = m;
    }
    co(r);

    return 0;
}
