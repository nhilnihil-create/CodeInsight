#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

struct union_find{
    vector<ll> parent;
    vector<ll> nums;
    union_find(ll n){
        parent.resize(n);
        nums.resize(n, 1LL);
        rep(i, 0, n) parent[i] = i;
    }

    ll root(ll x){
        if(parent[x] == x) return x;
        parent[x] = root(parent[x]);
        return parent[x];
    }

    void unite(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx != ry){
            parent[rx] = ry;
            nums[ry] += nums[rx];
        }
    }

    bool same(ll x, ll y){
        ll rx = root(x);
        ll ry = root(y);
        if(rx == ry) return true;
        return false;
    }

    ll size(ll x){
        return nums[root(x)];
    }
};  

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m);
    rep(i, 0, m) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    } 
    ll ans = 0;
    rep(i, 0, m) {
        struct union_find t(n);
        rep(j, 0, m) {
            if(i == j) continue;
            t.unite(a[j], b[j]);
        }
        if(t.size(t.root(0)) != n) ans++;
    }
    cout << ans << endl;
    return 0;
}