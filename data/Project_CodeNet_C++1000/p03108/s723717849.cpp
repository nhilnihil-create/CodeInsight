#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct union_find {
    vector<int> par;

    union_find(int n) : par(n, -1) { }

    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }

    bool unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return false;
        if (par[rx] > par[ry]) swap(rx, ry);
        par[rx] += par[ry];
        par[ry] = rx;
        return true;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
    ll n, m;
    cin >> n >> m;
    union_find tree(n);
    vector<pair<ll, ll>> bridge(m);
    for(int i = 0; i < m; i++){
        cin >> bridge[i].first >> bridge[i].second;
    }
    vector<ll> ans(m, 0);
    ans[0] = n * (n - 1) / 2;
    reverse(bridge.begin(), bridge.end());
    for (int i = 0; i < m-1; i++)
    {
        ans[i+1] = ans[i];
        ll x = bridge[i].first -1;
        ll y = bridge[i].second -1;
        ll xs = tree.size(x);
        ll ys = tree.size(y);
        if (tree.same(x, y) == false)
        {
            ans[i+1] -= xs * ys;
        }
        tree.unite(x,y);
    }

    reverse(ans.begin(), ans.end());
    for(int i = 0; i < m; i++){
        cout << ans[i] << endl;
    }
}
