#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
#define ld long double
#define PB push_back
#define lc 2 * v
#define rc 2 * v + 1
#define mid (s + e) / 2
#define pii pair <int , int>
#define pll pair <long long , long long>
#define FAST ios::sync_with_stdio(false);cin.tie(0);
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

const ll maxn = 3e5 + 20 , N = 60000 + 20 , mod = 1e9 + 7 , INF = 1e9 + 1 , lg = 32;

ll dis , d[maxn] , sz[maxn] , root;
vector <int> edges[maxn];
map <ll , int> mp;
set <ll> s;

void dfs(int v , int par, int h) {
    dis += h;
    for (auto u : edges[v]) {
        if(u != par) {
            dfs(u , v , h + 1);
        }
    }
}

void sfd(int v , int par) {
    for (auto u : edges[v]) {
        if(u != par) {
            cout << v << ' ' << u << '\n';
            sfd(u , v);
        }
    }
}

int main() {
    FAST
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
        mp[d[i]] = i;
        s.insert(d[i]);
    }
    // sort(D , D + n);
    fill(sz , sz + maxn , 1);

    while(s.size() > 1) {
        ll di = *s.rbegin(); s.erase(di);
        ll v = mp[di];
        ll val_par = di - n + (2 * (sz[v]));
        ll par = mp[val_par];

        if(par == 0) {
            cout << -1 << '\n';
            return 0;
        }
        else {
            edges[v].PB(par);
            edges[par].PB(v);
            sz[par] += sz[v];
        }

    }
    dfs(1 , -1 , 0);
    // cout << dis << ' ' << d[1] << endl;
    // sfd(1 , -1);
    if(dis == d[1]) {
        sfd(1 , -1);
    }
    else {
        cout << -1 << '\n';
    }
}
