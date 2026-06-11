#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
const long double PI = acos(-1.0L);
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

template <typename T>
struct SegTree {
    typedef function<T(T, T)> F;
    int n;
    F f;
    T ti;
    vector<T> dat;
    SegTree(){}
    SegTree(F f, T ti): f(f), ti(ti){}

    void init(int n_) {
        n = 1;
        while(n < n_) n <<= 1;
        dat.assign(n<<1, ti);
    }

    void build(const vector<T> &v) {
        int n_ = v.size();
        init(n_);
        for(int i = 0; i < n_; ++i) dat[n+i] = v[i];
        for(int i = n-1; i; --i) dat[i] = f(dat[(i<<1)|0], dat[(i<<1)|1]);
    }

    void set_val(int k, T x) {
        dat[k += n] = x;
        while(k >>= 1) dat[k] = f(dat[(k<<1)|0], dat[(k<<1)|1]);
    }

    T query(int a, int b) {
        if(a >= b) return ti;
        T vl = ti, vr = ti;
        for(int l = a+n, r = b+n; l < r; l >>= 1, r >>= 1) {
            if(l&1) vl = f(vl, dat[l++]);
            if(r&1) vr = f(dat[--r], vr);
        }
        return f(vl, vr);
    }

    template <typename C>
    int find(int st, C &check, T &acc, int k, int l, int r) {
        if(l+1 == r) {
            acc = f(acc, dat[k]);
            return check(acc) ? k-n : -1;
        }
        int m = (l+r)>>1;
        if(m <= st) return find(st, check, acc, (k<<1)|1, m, r);
        if(st <= 1 && !check(f(acc, dat[k]))) {
            acc = f(acc, dat[k]);
            return -1;
        }
        int vl = find(st, check, acc, (k<<1)|0, l, m);
        if(~vl) return vl;
        return find(st, check, acc, (k<<1)|1, m, r);
    }

    template <typename C>
    int find(int st, C &check) {
        T acc = ti;
        return find(st, check, acc, 1, 0, n);
    }
};

int n;

int main() {
    cin >> n;
    vector<ll> hvec(n, 0);
    for(int i = 0; i < n; ++i) {
        cin >> hvec.at(i);
        hvec.at(i)--;
    }
    vector<ll> avec(n, 0);
    for(int i = 0; i < n; ++i) cin >> avec.at(i);

    auto f = [](ll a, ll b) { return max(a, b); };
    SegTree<ll> seg(f, 0);
    seg.build(vector<ll>(n, 0));
    for(int i = 0; i < n; ++i) {
        ll pre = seg.query(0, hvec.at(i));
        seg.set_val(hvec.at(i), pre+avec.at(i));
    }
    cout << seg.query(0, n) << endl;
}