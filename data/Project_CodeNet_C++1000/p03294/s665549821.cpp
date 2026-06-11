#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

// ll m;
// ll g(ll a){
//     return m%a;
// }

// ll f(vector<ll> A){
//     ll ans;
//     for(ll x : A){
//         ans+=g(x);
//     }
// }

int main() {
    int n; cin >> n;
    vector<ll> x(n);
    rep(i,n){
        cin >> x[i];
    }
    ll ans=0;
    rep(i,n){
        ans+=x[i]-1;
    }
    cout << ans << endl;
}