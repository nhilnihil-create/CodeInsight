#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
using namespace std;
using ll = long long int;

ll N, A[100010], X[100010];

const int SIZE = 1 << 17;
struct SegmentTree {
    int node[2*SIZE];
    SegmentTree() { fill(node, node + 2*SIZE, 0); }
    void reset()  { fill(node, node + 2*SIZE, 0); }
    void update(int x, int val) {
        x += SIZE - 1; node[x] += val;
        while(x > 0) {
            x = (x - 1) / 2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }
    int query(int a, int b, int l=0, int r=SIZE, int k=0) {
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        int mid = (l + r) / 2;
        int vl = query(a, b, l, mid, 2*k+1);
        int vr = query(a, b, mid, r, 2*k+2);
        return vl + vr;
    }
};

SegmentTree seg;
bool solve(ll K) {
    seg.reset();
    vector< pair<int, int> > val_idx;
    for(int i=0; i<N; i++) {
        X[i] = (i == 0 ? 0 : X[i-1]) + (A[i] < K ? -1 : 1);
        val_idx.emplace_back(X[i], i);
    }
    val_idx.emplace_back(0, -1);
    sort(val_idx.begin(), val_idx.end());

    ll sum = 0;
    for(int i=N; i>=0; i--) {
        int val, idx; tie(val, idx) = val_idx[i];
        // fprintf(stderr, "K = %lld, val = %d, idx = %d\n", K, val, idx);
        sum += seg.query(idx, N);
        if(idx >= 0) seg.update(idx, 1);
    }
    // fprintf(stderr, "# K = %lld, sum = %lld\n", K, sum);
    return 2 * sum >= N * (N + 1) / 2;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    if(N == 1) {
        cout << A[0] << endl;
    }
    else {
        ll ub = 1e9 + 10, lb = -1;
        while(ub - lb > 1) {
            ll mid = (ub + lb) / 2;
            if(solve(mid)) {
                lb = mid;
            }
            else {
                ub = mid;
            }
        }
        cout << lb << endl;
        return 0;
    }
}
