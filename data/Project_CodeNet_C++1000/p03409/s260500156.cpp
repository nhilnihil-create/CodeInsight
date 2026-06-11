#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    const T e;
    const F f;
    size_t sz;
    vector<T> tree;

    SegmentTree(size_t n, const F &f, const T &e = 0) : f(f), e(e) {
        sz = 1;
        while(sz < n) sz <<= 1;
        tree.assign(2*sz, e);
    }

    void set(typename vector<T>::iterator begin, typename vector<T>::iterator end) {
        copy(begin, end, tree.begin() + sz);
        for(size_t k=sz-1; k>0; k--)
            tree[k] = f(tree[2*k+0], tree[2*k+1]);
    }

    void update(size_t k, const T &x) {
        k += sz;
        tree[k] = x;
        while(k >>= 1)
            tree[k] = f(tree[2*k+0], tree[2*k+1]);
    }

    T query(size_t a, size_t b) const {
        T l = e, r = e;
        for(a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
            if(a & 1) l = f(l, tree[a++]);
            if(b & 1) r = f(tree[--b], r);
        }
        return f(l, r);
    }

    T operator[](const size_t k) const {
        return tree[sz + k];
    }
};

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;

    using P = tuple<ll,ll,ll>;
    vector<P> v(2*n);
    for(ll i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i] = P(x, 1, y);
    }
    for(ll i=0; i<n; i++) {
        ll x, y;
        cin >> x >> y;
        v[i+n] = P(x, 0, y);
    }

    sort(v.begin(), v.end());

    SegmentTree<long> st(2*n, [&](long a, long b){return max(a, b);}, 0);
    ll r = 0;
    for(auto &t: v) {
        ll x, y, z;
        tie(x, z, y) = t;
        if(z == 1) {
            // red
            st.update(y, st[y]+1);
        } else {
            // blue
            if(!st.query(0, y)) continue;
            ll ok = 0, ng = y;
            while(abs(ok - ng) > 1) {
                ll m = (ok + ng) / 2;
                (st.query(m, y) ? ok : ng) = m;
            }
            st.update(ok, st[ok]-1);
            r++;
        }
    }
    cout << r << endl;
}
