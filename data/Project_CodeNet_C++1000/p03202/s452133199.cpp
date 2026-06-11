#include <bits/stdc++.h>
using namespace std;
//#define DEBUG_MODE
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

const ll INF = 5e15;

void sort_and_unique(V<ll> &v, bool rev = false) {
    sort(ALL(v));
    auto ite = unique(ALL(v));
    v.erase(ite, v.end());
    if(rev) reverse(ALL(v));
}

int main() {
    init_io();
    ll N;
    cin >> N;
    V<ll> A(N);
    ll pre = -1;
    bool is_one = true;
    for(ll &e : A) {
        cin >> e;
        if(pre >= e) is_one = false;
        pre = e;
    }
    if(is_one) {
        cout << 1 << endl;
        return 0;
    }
    A.push_back(0);

    V<ll> czip = A;
    sort_and_unique(czip);
    V<ll> idxv;
    for(ll e : A) {
        auto ite = lower_bound(ALL(czip), e);
        ll idx = distance(czip.begin(), ite);
        idxv.push_back(idx);
    }

    ll ok = 1e9, ng = 1;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        V<ll> pows = {1};
        for(ll i = 0;; i++) {
            ll nxt = pows[i] * mid;
            pows.push_back(nxt);
            if(nxt >= 1e6) break;
        }
        V<ll> added;
        DEBUG(mid);
        V<ll> cnt(czip.size(), 0);
        DEBUG(cnt);
        for(ll i = 1; i < N + 1; i++) {
            ll preh = A[i - 1];
            if(preh <= A[i]) {
                if(preh == A[i]) {
                    cnt[idxv[i]]++;
                    added.push_back(idxv[i]);
                }
                continue;
            }
            cnt[idxv[i]]++;
            added.push_back(idxv[i]);
            sort_and_unique(added);
            if(added.back() > idxv[i]) {
                for(ll j = added.size() - 1; ; j--) {
                    ll idx1 = added[j], idx2 = added[j - 1];
                    ll dic = czip[idx1] - czip[idx2];
                    ll num = cnt[idx1];
                    cnt[idx1] = 0;
                    if(dic < pows.size()) cnt[idx2] += num / pows[dic];
                    if(idx2 == idxv[i]) break;
                    added.pop_back();
                }
            }
            DEBUG(cnt);
            added.push_back(idxv[i]);
            for(ll j = idxv[i]; j >= 1; j--) {
                ll dic = czip[j] - czip[j - 1];
                if(dic >= pows.size()) break;
                ll num = cnt[j];
                ll carry_up = num / pows[dic];
                if(carry_up == 0) break;
                cnt[j] = num % pows[dic];
                cnt[j - 1] += carry_up;
                added.push_back(j - 1);
            }
        }
        DEBUG(cnt);
        DEBUG("->");
        /*
        for(ll i = czip.size() - 1; i >= 1; i--) {
            ll tmp = st.query(modified[i], carried);
            if(tmp < i) cnt[i] = 0;
            modified[i] = carried;
            ll dic = czip[i] - czip[i - 1];
            if(dic >= pows.size()) continue;
            cnt[i - 1] += cnt[i] / pows[dic];
        }
        */
        DEBUG(cnt);
        if(cnt[0] <= 1) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
