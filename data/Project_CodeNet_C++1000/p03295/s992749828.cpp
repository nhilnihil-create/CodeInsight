#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> a(m);
    rep(i, m)cin >> a[i].first >> a[i].second;
    sort(all(a));
    ll ans = 1, mi = inf;
    rep(i, m){
        mi = min(mi, a[i].second);
        if(mi <= a[i].first){
            mi = a[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}
