#include <iostream> 
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#include<queue>
#include<deque>
#include<iomanip>
#include<sstream>
#include<cmath>
#include<tuple>
#include<bitset>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define req(i,n) for(ll i = 1;i <=  n; i++)
#define rrep(i,n) for(ll i = n -1;i >= 0;i--)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
typedef long double ld;
const ll INF = 1e9;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T & val) {
	std::fill((T*)array, (T*)(array + N), val);
}ll n,sum = 0,m,a,b;
struct UnionFind {
    vector<int> par;
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    bool unite(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
    cin >> n >> m; UnionFind tree(2*n);
    rep(i, m) {
        cin >> a >> b;
        a--; b--;
        tree.unite(a, b + n);
        tree.unite(a + n, b);
    }ll cnt = 0;
    if (tree.same(0, n)) {
        cout << n * (n - 1) / 2 - m << endl;
    }
    else {
        rep(i, n) {
            if (tree.same(0, i)) cnt++;
        }cout << cnt * (n - cnt) - m << endl;
    }
}