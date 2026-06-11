#include <bits/stdc++.h>
template<class T> inline bool chmin(T&a, T b){if(a > b){a = b; return true;}else{return false;}}
template<class T> inline bool chmax(T&a, T b){if(a < b){a = b; return true;}else{return false;}}
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1.0)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<ll> a(x), b(y), c(z);
    rep(i, x)cin >> a[i];
    rep(i, y)cin >> b[i];
    rep(i, z)cin >> c[i];
    sort(rall(a));
    sort(rall(b));
    sort(rall(c));
    vector<ll> ans(k);
    priority_queue<tuple<ll, ll, ll, ll>> que;
    que.push(make_tuple(a[0] + b[0] + c[0], 0, 0, 0));
    ll ma = 0, mb = 0, mc = 0;
    map<tuple<ll, ll, ll>, ll> mp;
    rep(i, k){
        tuple<ll, ll, ll, ll> now = que.top();
        que.pop();
        ll pa = get<1>(now), pb = get<2>(now), pc = get<3>(now);
        if(mp[make_tuple(pa, pb, pc)]){
            i--;
            continue;
        }
        ans[i] = get<0>(now);
        mp[make_tuple(pa, pb, pc)]++;
        if(pa < x-1)que.push(make_tuple(a[pa+1] + b[pb] + c[pc], pa+1, pb, pc));
        if(pb < y-1)que.push(make_tuple(a[pa] + b[pb+1] + c[pc], pa, pb+1, pc));
        if(pc < z-1)que.push(make_tuple(a[pa] + b[pb] + c[pc+1], pa, pb, pc+1));
    }
    rep(i, k)cout << ans[i] << endl;
}