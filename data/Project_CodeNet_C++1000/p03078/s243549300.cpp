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
    vector<ll> d, ans;
    rep(i, x)rep(j, y)d.push_back(a[i] + b[j]);
    sort(rall(d)); sort(rall(c));
    rep(i, min(x*y, k)){
        rep(j, min(z, k)){
            ans.push_back(d[i] + c[j]);
        }
    }
    sort(rall(ans));
    rep(i, k)cout << ans[i] << endl;
}
