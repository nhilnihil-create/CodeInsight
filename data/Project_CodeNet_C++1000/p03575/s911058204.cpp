/*
    Problem 86
    https://atcoder.jp/contests/abc075/tasks/abc075_c
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
    DisjointSet (int size) {d.assign(size, -1);}
    int find(int x) { return (d[x] < 0) ? x : d[x] = find(d[x]); }
    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return false;
        if (d[x] > d[y]) swap(x, y);
        d[x] += d[y];
        d[y] = x;
        return true;
    }
    bool same(int x, int y) {return find(x) == find(y);}
    int size(int x) {return -d[find(x)];}
};
/* global variables */
/* function */
/* main */
int main(){
    int N, M;
    cin >> N >> M;
    vector<pii> p(M);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        p[i] = pii(x, y);
    }
    int ans = 0;
    for (pii exclusion : p) {
        DisjointSet ds = DisjointSet(N);
        for (pii edge : p) {
            if (edge == exclusion) continue;
            ds.unite(edge.first, edge.second);
        }
        if (ds.size(0) != N) ans++;
    }
    cout << ans << '\n';
}