#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifdef DEBUG
#include "inc/debug.hpp"
#else
#define debug(...) 42
#endif

class Sg {
public:
    int n;
    vector<ll> nodes;
    Sg(int _n) {
        n = 1;
        while (n < _n) n *= 2;
        nodes.resize(n*2-1, 0);
    }
    void add(int i, int x) {
        i += n-1;
        nodes[i] += x;
        while (i > 0) {
            i = (i-1)/2;
            nodes[i] = nodes[i*2+1] + nodes[i*2+2];
        }
    }
    ll sum(int l, int r) {
        return _sum(l, r, 0, 0, n);
    }
    ll _sum(int l, int r, int k, int tl, int tr) {
        if (l <= tl && tr <= r) return nodes[k];
        if (tr <= l || r <= tl) return 0;
        ll sl = _sum(l, r, k*2+1, tl, (tl+tr)/2);
        ll sr = _sum(l, r, k*2+2, (tl+tr)/2, tr);
        return sl + sr;
    }
};

// 中央値がk以下となる部分列を数える
ll f(vector<int> &a, int k) {
    int N = a.size();
    vector<int> t(N);
    for (int i=0; i<N; ++i) {
        t[i] = (a[i] <= k) ? 1 : -1;
    }

    vector<int> cu(N+1);
    cu[0] = 0;
    for (int i=0; i<N; ++i) {
        cu[i+1] = cu[i] + t[i];
    }
    Sg sg(N*2+1);
    ll ret = 0;
    for (int i=0; i<N+1; ++i) {
        ret += sg.sum(0, cu[i]+N);
        sg.add(cu[i]+N, 1);
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N;
    cin >> N;
    vector<int> a(N);
    for (int i=0; i<N; ++i) cin >> a[i];

    ll p = (N*(N+1)/2)/2+1;
    int l = 0;
    int r = 1000000001;
    while (r - l > 1) {
        int mid = (l+r)/2;
        if (f(a, mid) >= p) r = mid;
        else l = mid;
    }
    cout << r << endl;

    return 0;
}