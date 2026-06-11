#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <tuple>
#include <queue>
#include <bitset>
#include <set>
#include <map>
#include <list>

using ll = long long;
using ld = long double;
using namespace std;
const int INF = 1e9+100;
const ll INF64 = 7e18l;
const int mod = 1000000007;
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(), (a).end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);


struct union_find {
    vector<int> parent;
    vector<int> size;
    int components = 0;

    union_find(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        components = n;
        for (int i = 0; i <= n; ++i) 
            parent[i] = i;
    }

    int find(int v) {
        return v == parent[v] ? v : parent[v] = find(parent[v]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (size[u] < size[v]) 
            swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        --components;
        return true;
    }
};

int main() {
    FIN;
    ll n,m; cin >> n >> m;
    vector<pair<int,int>> ab(m); // つながってる頂点のpair
    for(ll i=0;i<m;i++){
        int a,b; cin >> a >> b;
        a--; b--;
        ab[i] = pair<int,int>(a,b);
    }

    ll ans = n*(n-1)/2;
    vector<ll> res(m);
    union_find UF(n); // 頂点の数
    for(ll i=m-1;i>=0;i--){
        res[i] = ans;
        int par_a = UF.find(ab[i].first); // 親の頂点をみつける
        int par_b = UF.find(ab[i].second);
        if(par_a == par_b) continue;
        ans -= UF.size[par_a] * UF.size[par_b]; //sizeを出すためにはfind必要
        UF.unite(ab[i].first,ab[i].second); // 頂点のpairをつなげる
    }

    rep(i,0,m) cout << res[i] << endl;

    return 0;
}

