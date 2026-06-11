//二重ループは真ん中で分ける！
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int n; cin >> n;
    ll ans=0;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    vector<ll> b(n); rep(i,n) cin >> b[i];
    vector<ll> c(n); rep(i,n) cin >> c[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    
    rep(i,n){
        auto it_a = lower_bound(a.begin(),a.end(),b[i]);
        ll index_a = it_a - a.begin();
        
        auto it_c = upper_bound(c.begin(),c.end(),b[i]);
        ll index_c = it_c - c.begin();
        // cout << index_a << index_c << endl;
        ans += (n-index_c)*(index_a);
        
    }
    
    cout << ans << endl;
}