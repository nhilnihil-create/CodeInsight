#include <bits/stdc++.h>
#define rep(i,a,n) for(ll i = a;i < n;i++)
typedef long long ll;
using namespace std;

signed main(){
    ll n,k;
    cin >> n >> k;

    ll ans = 0;
    rep(i,k+1,n+1){
        ans += (i-k)*(n/i);
        if(k == 0) ans += max(0LL,n-(n/i)*i-k);
        else ans += max(0LL,n-(n/i)*i-k+1);
    }

    cout << ans << endl;
    return 0;
}