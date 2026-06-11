//https://atcoder.jp/contests/agc040/tasks/agc040_b

#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <limits>
#include <stack>
#include <math.h>
#define REP(i,n) for(ll i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n) for(ll i=(n)-1; i>=0; --i)
#define SREP(i,s,n) for(ll i=(s), i##_len=(n); i<i##_len; ++i)
#define ALL(v) (v).begin(),(v).end()
#define INF (ll(1e18))

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

template <typename T>
T gcd(T a, T b) {
    if(a < b) gcd(b, a);
    if (b == 1) return 1;
    T r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
    if (a.second == b.second) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    
    UnionFind(int n = 1) {
        init(n);
    }
    
    void init(int n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) {
            par[i] = i;
            rank[i] = 0;
        }
    }
    
    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        return true;
    }
};

class SegmentTree {
public:
    int N, n;
    vector<ll> value;
    SegmentTree(int n) {
        this->n = n;
        this->N = 1;
        while (N < n) N *= 2;
        this->value = vector<ll>(2 * N - 1, INF);
    }
    
    void update(int i, ll x) {
        i += N - 1;
        value[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            value[i] = min(value[i * 2 + 1], value[i * 2 + 2]);
        }
    }
    
    ll query(int l, int r) {
        return _query(l, r, 0, 0, N);
    }
    
    ll _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b)
            return value[k];
        else {
            ll c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2);
            ll c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r);
            return min(c1, c2);
        }
    }
};

#define MOD (1000000007)

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, C;
    cin >> N >> C;
    vector<tuple<ll, ll, ll>> stc(N);
    REP(i, N) {
        cin >> get<0>(stc[i]) >> get<1>(stc[i]) >> get<2>(stc[i]);
    }
    sort(stc.begin(), stc.end());
    vector<pair<ll,ll>> r(C);
    REP(i, N) {
        ll s = get<0>(stc[i]);
        ll t = get<1>(stc[i]);
        ll c = get<2>(stc[i]);
        REP(j, C) {
            ll pt = r[j].first;
            ll pc = r[j].second;
            if ( (pc == c && pt <= s) || (pc != c && pt < s) ) {
                r[j].first = t;
                r[j].second = c;
                break;
            }
        }
    }
    ll cnt = 0;
    REP(j, C) {
        cnt += int(r[j].first > 0);
    }
    cout << cnt << endl;
}
