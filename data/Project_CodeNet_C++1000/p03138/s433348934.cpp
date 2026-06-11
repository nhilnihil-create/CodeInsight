#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    ll keta = 0;
    ll tmp = k;
    while(tmp){
        tmp >>= 1;
        ++keta;
    }
    ll ans = 0;
    for(i = 60;i >= keta;--i){
        rep(j,n){
            if(a.at(j) & (1ll << i)) ans += (1ll << i);
        }
    }
    bool flag = true;
    for(i = keta-1;i >= 0;--i){
        ll k1 = 0;
        ll k2 = 0;
        rep(j,n){
            if(a.at(j) & (1ll << i)) k1 += 1;
            else k2 += 1;
        }
        if(!flag) ans += max(k1,k2)*(1ll << i);
        else{
            if(!(k & (1ll << i))) ans += k1*(1ll << i);
            else if(k1 >= k2){
                ans += k1*(1ll << i);
                flag = false;
            }else{
                ans += k2*(1ll << i);
            }
        }
    }
    cout << ans << endl;

    return 0;
}