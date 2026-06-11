#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    int n,m;
    cin >> n >> m;
    ve<int> a(m);
    rep(i,m) cin >> a[i];
    sort(a.begin(), a.end());
    ve<int> sa(m-1);
    rep(i,m-1) sa[i] = a[i+1] - a[i];
    sort(sa.rbegin(), sa.rend());
    int ans = a[m-1]-a[0];
    if(n >= m){
        ans = 0;
        cout << ans << endl;
        return 0;
    }
    rep(i,n-1){
        ans -= sa[i];
    }
    cout << ans << endl;
    return 0;
}