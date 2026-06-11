/*
    Problem 87
    https://atcoder.jp/contests/abc120/tasks/abc120_d
*/
#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* class */
class DisjointSet {
public:
    vector<int> d;
    DisjointSet () {}
    DisjointSet (int size) {
        d.assign(size, -1);
    }

    int find (int x) {
        if (d[x] < 0) return x;
        return d[x] = find(d[x]);
    }
    bool unite (int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same (int x, int y) { return find(x) == find(y); }
    int size (int x) { return -d[find(x)];}
};
/* global variables */
/* function */
ll comb2(ll x) { return x * (x-1) / 2; }
/* main */
int main(){
    int N, M;
    cin >> N >> M;
    vector<pii> v(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        v[i] = pii(x, y);
    }
    reverse(v.begin(), v.end());
    DisjointSet ds = DisjointSet(N);
    vector<ll> totalVec;
    ll totalPair = comb2(N);
    for (pii p : v) {
        totalVec.push_back(totalPair);
        int x = p.first, y = p.second;
        if (ds.same(x, y)) continue;
        ll c1 = comb2(ds.size(x)), c2 = comb2(ds.size(y));
        ds.unite(x, y);
        ll cAfter = comb2(ds.size(x));
        totalPair += c1 + c2;
        totalPair -= cAfter;
    }
    for (int i = totalVec.size()-1; i>=0; i--)
        cout << totalVec[i] << '\n';
}