#include <bits/stdc++.h>

#define rep(n) for(int i=0;i<n;i++)
#define repp(j, n) for(int j=0;j<n;j++)
#define reppp(i, m, n) for(int i=m;i<n;i++)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define debug(x) cerr << #x << ": " << x << endl

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Pll;
typedef pair<int, int> Pii;
struct edge{int from, to; ll cost;};

const ll MOD = 1000000007;
const long double EPS = 1e-10;

template<class Abel> class UnionFind {
    public:
    int n;
    vector<int> par, rank;
    vector<Abel> diff_weight;

    UnionFind(int n, Abel SUM_UNITY = 0) {
        rep(n) {
            par.push_back(i);
            rank.push_back(0);
            diff_weight.push_back(SUM_UNITY);
        }
    }

    int find(int x) {
        if(par[x] == x){
            return x;
        }
        int root = find(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = root;
    }

    Abel weight(int x) {
        find(x);
        return diff_weight[x];
    }

    bool unite(int x, int y, Abel w) {
        w = w + weight(x) - weight(y);
        x = find(x);
        y = find(y);

        if(x == y) return false;

        if(rank[x] < rank[y]){
            par[x] = y;
            diff_weight[x] = -w;
        }else{
            par[y] = x;
            diff_weight[y] = w;
            if(rank[x] == rank[y]) rank[x]++;
        }

        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }

    bool is_same(int x, int y) {
        return find(x) == find(y);
    }
};

int main() {
    std::ios::sync_with_stdio(0); cin.tie(0);
    int n,m,l,r,d;
    cin >> n >> m;

    UnionFind<int> uf(n+1);

    rep(m){
        cin >> l >> r >> d;
        if(!uf.unite(l, r, d) && uf.diff(l, r) != d){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}