#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; i++)
#define reps(i, s, n) for(ll i = (s), i##_len = (n); i < i##_len; i++)
#define rrep(i, n) for(ll i = (n) - 1; i >= 0; i--)
#define rreps(i, e, n) for(ll i = (n) - 1; i >= (e); i--)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((ll)(x).size())
#define len(x) ((ll)(x).length())
#define endl "\n"
template<class T> void chmax(T &a, const T b){ a = max(a, b); }
template<class T> void chmin(T &a, const T b){ a = min(a, b); }

template<typename T>
struct Compress {
private:
    vector<T> value;
    
public:
    Compress() {}
    Compress(const vector<T> &v, bool distinct = true) {
        int n = v.size();
        value.resize(n);
        value = v;
        sort(value.begin(), value.end());
        if (distinct) value.erase(unique(value.begin(), value.end()), value.end());
    }
    
    int size() {
        return value.size();
    }
    
    int val(int idx) {
        return value[idx];
    }
    
    int get(int v) {
        return lower_bound(value.begin(), value.end(), v) - value.begin();
    }
};

template<class T>
struct SegmentTree {
private:
    int n;
    vector<T> node;
    T def;
    function<T(T,T)> lop;
    function<T(T,T)> out;
    
public:
    SegmentTree() {}
    SegmentTree(const vector<T> &v, T _def, function<T(T,T)> _lop, function<T(T,T)> _out) {
        int vl = (int)v.size();
        n = 1;
        while(n < vl) n *= 2;
        def = _def; lop = _lop; out = _out;
        node = vector<T>(2 * n - 1, def);
        for(int i = 0; i < vl; i++) node[i + n - 1] = v[i];
        for(int i = n - 2; i >= 0; i--) node[i] = out(node[i * 2 + 1], node[i * 2 + 2]);
    }
    
    void update(int idx, T val) {
        idx += (n - 1);
        node[idx] = lop(node[idx], val);
        while(idx > 0) {
            idx = (idx - 1) / 2;
            node[idx] = out(node[idx * 2 + 1], node[idx * 2 + 2]);
        }
    }
    
    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r < 0) r = n;
        if ((r <= a) || (b <= l)) return def;
        if ((a <= l) && (r <= b)) return node[k];
        return out(query(a, b, 2 * k + 1, l, (l + r) / 2), query(a, b, 2 * k + 2, (l + r) / 2, r));
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    // ifstream in("input.txt");
    // cin.rdbuf(in.rdbuf());
    ll n;
    cin >> n;
    vector<ll> h(n), a(n);
    rep(i, n) cin >> h[i];
    rep(i, n) cin >> a[i];
    Compress<ll> ch(h);
    auto lop = [](ll a, ll b){ return b; };
    auto out = [](ll a, ll b){ return max(a, b); };
    SegmentTree<ll> st(vector<ll>(ch.size(), 0), 0, lop, out);
    rep(i, n) {
        ll idx = ch.get(h[i]);
        ll val = st.query(0, idx);
        st.update(idx, val + a[i]);
    }
    cout << st.query(0, ch.size()) << endl;
    return 0;
}
