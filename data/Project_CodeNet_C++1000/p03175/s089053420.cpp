#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;

vector<vector<int>> to(100000);
ll mod = 1000000007;
P dfs(int v, int p = -1){
    if(to[v].size() == 1 && to[v][0] == p){
        return make_pair(1, 1);
    }
    ll b = 1;
    ll w = 1;
    for(int t : to[v]){
        if(t == p)continue;
        P p = dfs(t, v);
        (b *= p.first) %= mod;
        (w *= (p.first + p.second)) %= mod;
    }
    return make_pair(w, b);
}

int main() {
    int n;
    cin >> n;
    rep(i, n-1){
        int x, y;
        cin >> x >> y;
        x--; y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    P p = dfs(0);
    ll ans = (p.first + p.second) % mod;
    cout << ans << endl;
}