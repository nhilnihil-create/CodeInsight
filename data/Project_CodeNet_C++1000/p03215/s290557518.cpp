//https://atcoder.jp/contests/dwacon5th-prelims/tasks/dwacon5th_prelims_b

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
    return a.second > b.second;
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

#define MOD (1000000007)
#define BIGNUM (ll(1e18))

int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    vector<ll> s(N+1, 0);
    REP(i, N) {
        cin >> a[i];
        s[i+1] = s[i]+a[i];
    }
    
    vector<ll> beauty;
    REP(i, N) {
        SREP(j, i+1, N+1) {
            ll b = s[j]-s[i];
            beauty.push_back(b);
        }
    }

    ll M = beauty.size();
    ll score = 0;
    REP(i, 64) {
        int bcnt = 0;
        REP(j, M) {
            if((((beauty[j] & score) == score) || score == 0)  && (beauty[j] & (1L << (63-i))))
                bcnt++;
        }
        if (bcnt>=K) {
            score += 1L << (63-i);
        }
    }
    cout << score << endl;
}
