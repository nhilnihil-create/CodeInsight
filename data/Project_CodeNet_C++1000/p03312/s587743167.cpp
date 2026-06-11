#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

void chmin(ll &a, const ll &b) { if (b < a) a = b; }
const ll INF = 1ll<<60;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i]; rep(i,n-1) a[i+1] += a[i];
    ll ans = INF;
    for(int i = 1; i <= n-3; i++){
        // left
        ll k = lower_bound(a.begin(),a.begin()+i+1,a[i]/2) - a.begin();
        if(k == i) k--;
        if(k != 0 && abs(a[k]*2-a[i]) > abs(a[k-1]*2-a[i])) k--;
        // right
        ll l = lower_bound(a.begin()+i+1,a.end(),(a[n-1]+a[i])/2) - a.begin();
        if(l == n-1) l--;
        if(l != i+1 && abs(a[n-1]-2*a[l]+a[i]) > abs(a[n-1]-2*a[l-1]+a[i])) l--;
        // change
        chmin(ans,max(max(a[k],a[i]-a[k]),max(a[n-1]-a[l],a[l]-a[i]))-min(min(a[k],a[i]-a[k]),min(a[n-1]-a[l],a[l]-a[i])));
    }
    cout << ans << endl;
}