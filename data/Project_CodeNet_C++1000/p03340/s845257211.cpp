#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    int r = 0;
    ll sum = 0;
    ll xo = 0;
    ll ans = 0;
    rep(l,n){
        while(r<n && (sum+a[r])==(xo^a[r])){
            sum += a[r];
            xo ^= a[r];
            r++;
        }
        ans += r-l;
        if(l==r)r++;
        sum -= a[l];
        xo ^= a[l];
    }
    cout << ans << endl;
    return 0;
}