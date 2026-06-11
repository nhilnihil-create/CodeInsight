// Template
#include <bits/stdc++.h>
#define rep_override(x, y, z, name, ...) name
#define rep2(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep3(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rep(...) rep_override(__VA_ARGS__, rep3, rep2)(__VA_ARGS__)
#define per(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
constexpr int inf = 1001001001;
constexpr ll INF = 3003003003003003003;
template <typename T> inline bool chmin(T& x, const T& y) {if (x > y) {x = y; return 1;} return 0;}
template <typename T> inline bool chmax(T& x, const T& y) {if (x < y) {x = y; return 1;} return 0;}
struct IOSET {IOSET() {cin.tie(0); ios::sync_with_stdio(0); cout << fixed << setprecision(10);}} ioset;

// Segment Tree
template <typename Operator>
struct SegmentTree {
    Operator OP;
    using NodeType = decltype(OP.NodeE);
    int length;
    vector<NodeType> node;
    SegmentTree (int n) {
        length = 1;
        while (length < n) length <<= 1;
        node.assign(length << 1, OP.NodeE);
    }
    SegmentTree (vector<NodeType> &vec) {
        length = 1;
        while (length < vec.size()) length <<= 1;
        node.assign(2 * length, OP.NodeE);
        rep(i, vec.size()) node[i + length] = vec[i];
        for (int i = length - 1; i > 0; --i) node[i] = OP.func(node[(i << 1) + 0], node[(i << 1) + 1]);
    }
    void update(int idx, NodeType val) {
        idx += length;
        node[idx] = OP.change(node[idx], val);
        while (idx >>= 1) node[idx] = OP.func(node[(idx << 1) + 0], node[(idx << 1) + 1]);
    }
    NodeType get(int l, int r) {
        l += length;
        r += length;
        NodeType vl = OP.NodeE, vr = OP.NodeE;
        while (r > l) {
            if (l & 1) vl = OP.func(vl, node[l++]);
            if (r & 1) vr = OP.func(node[--r], vr);
            l >>= 1;
            r >>= 1;
        }
        return OP.func(vl, vr);
    }
};
struct RMQ {
    using NodeType = ll;
    NodeType NodeE = 0LL;
    NodeType change(NodeType x, NodeType y) {return y;}
    NodeType func(NodeType x, NodeType y) {return max(x, y);}
};

// Main
int main() {
    int n;
    cin >> n;
    vector<int> h(n), a(n);
    rep(i, n) {cin >> h[i]; --h[i];}
    rep(i, n) cin >> a[i];
    
    SegmentTree<RMQ> st(n);
    rep(i, n) {
        ll x = st.get(0, h[i]);
        st.update(h[i], x + a[i]);
    }
    
    cout << st.get(0, n) << "\n";
    return 0;
}
