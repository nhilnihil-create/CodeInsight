/**
*    created: 16.05.2020 08:12:12
**/

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
const int inf =1000000000;

int main() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    int x = 0,y=0;
    //a<b[i],b[i]<c
    vector<ll> aa(n), cc(n); //aa,cc[i]:b[i]が選べるa,cの種類
    rep(i,n){
        auto itra = lower_bound(a.begin(), a.end(), b[i]);
        aa[i] = distance(a.begin(), itra);
        auto itrc = upper_bound(c.begin(), c.end(), b[i]);
        cc[i] = distance(itrc, c.end());
    }
    ll ans = 0;
    rep(i,n){
        ans += aa[i] * cc[i];
    }
    cout << ans << endl;
}