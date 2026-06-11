#include <bits/stdc++.h>
using namespace std;
 
using ll=long long;
 
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
const ll MOD = 1e9 + 7;

vector<int> primes(int n) {
    vector<bool> dps(n+1, true);
    vector<int> rets;
    for (int i = 2; i <= n; ++i) {
        if (!dps[i]) continue; 
        int j = 2*i; 
        while (j <= n) {
            dps[j] = false;
            j += i;
        } 
    }
    for (int j = 3; j <= n; j+=2) {
        if (dps[j] && dps[(j+1)/2]) rets.push_back(j);
    }
    return rets;
}

int main() {
    int mx = (1e5)-1;
    auto v = primes(mx);
    int q;
    cin >> q;
    vector<int> ls(q), rs(q);
    rep(i, q) cin >> ls[i] >> rs[i];
    rep(i, q){ 
        int ans = upper_bound(all(v), rs[i]) - lower_bound(all(v), ls[i]);
        cout << ans << endl;
    } 
    return 0;
}