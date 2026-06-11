#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if(k != 0){
        for(ll i=1; i<=n; i++){
            if(i <= k) continue;
            ll a = n/i;
            ll b = n%i;
            ll c = i-k;
            ans += c*a;
            if(b-(k-1) > 0) ans += b-(k-1);
        }
        cout << ans << endl;
    }else{
        cout << n*n << endl;
    }
    return 0;
}