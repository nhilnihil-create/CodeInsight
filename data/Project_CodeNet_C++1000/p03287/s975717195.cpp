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
    ll n, m, ans = 0;
    cin >> n >> m;
    vector<ll> a(n), sum(n);
    rep(i, n){
        cin >> a[i];
        a[i] %= m;
    }
    sum[0] = a[0];
    REP(i, n-1)sum[i] = (sum[i-1] + a[i]) % m;
    map<ll, ll> mp;
    mp[0]++;
    rep(i, n){
        ans += mp[sum[i]];
        mp[sum[i]]++;
    }
    cout << ans << endl;
}
