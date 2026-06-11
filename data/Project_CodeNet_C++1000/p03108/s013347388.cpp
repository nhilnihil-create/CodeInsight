#include <bits/stdc++.h>
#define loop2(i, s, n, a) for (int i = int(s); i < int(n); i += a)
#define loop(i, s, n) loop2(i, s, n, 1)
#define rep(i, n) loop(i, 0, n)

#define pb push_back
#define all(in) in.begin(),in.end()

using ll = long long;
using ull = unsigned long long;
using namespace std;

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) { }
    bool unionSet(int x, int y) {
        x = root(x);
        y = root(y);

        if (x != y) {
            if (data[y] < data[x]) swap(x, y); // xの方が小さい→→sizeはxの方が大きい
            data[x] += data[y];
            data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) { return root(x) == root(y); }
    int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); } // rootは-size,それ以外はroot(parent)
    int size(int x) { return -data[root(x)]; }
};

int main(){
    ll n, m; cin >> n >> m;
    vector<pair<ll,ll>> data(m);
    rep(i,m){
        ll a, b; cin >> a >> b;
        data[i].first = a-1;
        data[i].second = b-1;
    }

    vector<ll> ans(m,0);
    ans[m-1] = n*(n-1)/2;

    UnionFind an(n);

    for(ll i = m-1; i > 0; i--){
        ll count = an.size(data[i].first) * an.size(data[i].second);
        ans[i-1] = ans[i];
        if(an.unionSet(data[i].first, data[i].second)) ans[i-1] -= count;
    }
    rep(i,m) cout << ans[i] << endl;
}