#include <bits/stdc++.h>
using namespace std;
#define DEBUG_MODE
#define endl '\n'
#ifdef DEBUG_MODE
#define DEBUG(X) debug_func(X, #X)
#define DEBUG_ENDL endl << flush
#define DEBUG_SEPARATOR_LINE cout<<"=================\n"
#else
#define DEBUG(X) 0
#define DEBUG_ENDL 0
#define DEBUG_SEPARATOR_LINE 0
#endif
#define ALL(V) (V).begin(), (V).end()
#define ALLR(V) (V).rbegin(), (V).rend()
#define DEBUG_ENDL_S(S) ((S).size() ? "\n" : "") << flush;
template <typename T> using V = vector<T>;
template <typename T> using VV = V<V<T>>;
template <typename T, typename U> using P = pair<T, U>;
using ll = int64_t;
using PLL = P<ll, ll>;
template <typename T> const T& var_min(const T &t) { return t; }
template <typename T> const T& var_max(const T &t) { return t; }
template <typename Head, typename... Tail> const Head& var_min(const Head &head, const Tail&... tail) { return min(head, var_min(tail...)); }
template <typename Head, typename... Tail> const Head& var_max(const Head &head, const Tail&... tail) { return max(head, var_max(tail...)); }
template <typename T, typename... Tail> void chmin(T &t, const Tail&... tail) { t = var_min(t, tail...); }
template <typename T, typename... Tail> void chmax(T &t, const Tail&... tail) { t = var_max(t, tail...); }
void debug_func_preffix(const string &s) { if(s.size()) cout << s << " = "; }
template <typename T>
void debug_func(const T &t, const string &s = "") {
    debug_func_preffix(s);
    cout << t << DEBUG_ENDL_S(s);
}
template <typename T, typename U>
void debug_func(const P<T, U> &p, const string &s = "") {
    debug_func_preffix(s);
    cout << "(";
    debug_func(p.first);
    cout << ", ";
    debug_func(p.second);
    cout << ")" << DEBUG_ENDL_S(s);
}
template <typename T>
void debug_func(const V<T> &v, const string &s = "") {
    for(ll i = 0; i < v.size(); i++) {
        string t = s + "[" + to_string(i) + "]";
        debug_func(v[i], t);
    }
}

void init_io() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(30);
}

int main() {
    init_io();
    ll N;
    cin >> N;
    V<ll> A(N), B(N);
    for(ll &e : A) cin >> e;
    for(ll &e : B) cin >> e;
    ll ans = 0;
    for(ll i = 0; i < 30; i++) {
        V<ll> am, bm;
        ll cnt = 0;
        ll mod = (1ll << (i + 1));
        for(ll i = 0; i < N; i++) {
            am.push_back(A[i] % mod);
            bm.push_back(B[i] % mod);
        }
        sort(ALL(bm));
        ll dig1 = (1ll << i);
        ll dig2 = mod;
        V<PLL> ranges = {
            PLL(dig1, dig2),
            PLL(dig1 + dig2, dig2 * 2),
        };
        for(ll e : am) {
            for(const auto &p : ranges) {
                ll l, r;
                tie(l, r) = p;
                ll el = l - e;
                ll er = r - e;
                auto itel = lower_bound(ALL(bm), el);
                auto iter = lower_bound(ALL(bm), er);
                cnt += distance(itel, iter) % 2;
            }
        }
        ans += (cnt & 1 ? (1ll << i) : 0);
    }
    cout << ans << endl;
    return 0;
}
