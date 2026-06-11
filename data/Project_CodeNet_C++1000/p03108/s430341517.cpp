#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> links;
vector<ll> sizes;

ll root(ll z) {
    while (z!=links[z]) z = links[z];
    return z;
}

int main() {
    ll n, m, a, b;
    cin >> n >> m;
    ll res = n*(n-1)/2;
    vector<pair<ll,ll>> edges;
    for (ll i=0; i<m; i++) {
        cin >> a >> b;
        edges.push_back(make_pair(a,b));
    }
    for (ll i=0; i<=n; i++) {
        links.push_back(i);
        sizes.push_back(1);
    }
    vector<ll> result;
    for (ll i=m-1; i>=0; i--) {
        result.push_back(res);
        ll x = root(edges[i].first);
        ll y = root(edges[i].second);
        if (x==y) continue;
        res-=(sizes[x]*sizes[y]);
        if (sizes[x]<sizes[y]) swap(x,y);
        sizes[x]+=sizes[y];
        links[y] = x;
    }
    for (ll i=m-1; i>=0; i--) cout << result[i] << endl;
    return 0;
}