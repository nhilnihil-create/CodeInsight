#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long int;

struct UnionFind
{
    vector<int> parent;
    vector<ll> siz;
    ll ineq; // 「不便さ」
    UnionFind(ll n) : parent(n), siz(n), ineq(n*(n-1)/2){
        for(int i = 0; i < n; i++) parent[i] = i;
        siz.assign(n, 1);
    }
 
    int root(int x){
        return x == parent[x] ? x : (parent[x] = root(parent[x]));
    }
 
    void unite(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx != ry){
            if(rx > ry) swap(rx, ry);

            ineq -= siz[rx]*siz[ry];
            parent[rx] = parent[ry];
            siz[ry] += siz[rx];
        }
        return;
    }
};

int main()
{
    int n, m; cin >> n >> m;
    UnionFind u(n);
    vector<pair<int, int> > bridges(m);
    rep(i, m){
        int ai, bi; cin >> ai >> bi;
        bridges[i] = make_pair(ai-1, bi-1);
    }

    vector<ll> ans(m);
    reverse(bridges.begin(), bridges.end());
    ans[0] = u.ineq;
    rep(i, m-1){
        u.unite(bridges[i].first, bridges[i].second);
        ans[i+1] = u.ineq;
    }

    reverse(ans.begin(), ans.end());
    rep(i, m){
        cout << ans[i] << endl;
    }
    return 0;
}