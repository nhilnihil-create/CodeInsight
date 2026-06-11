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
    vector<ll> tmpa(n+1,0);
    for(i = 0;i < n;++i){
        tmpa.at(i+1) = tmpa.at(i) + a.at(i);
    }
    vector<ll> sum;
    for(i = 0;i < n;++i){
        for(j = i+1;j <= n;++j){
            ll tmp = tmpa.at(j) - tmpa.at(i);
            sum.push_back(tmp);
        }
    }
    ll ans = 0;
    for(i = 40;i >= 0;--i){
        ll cnt = 0;
        ll tmp = ans|(1LL << i);
        rep(j,sum.size()){
            if((sum.at(j) & tmp) == tmp) ++cnt;
        }
        if(cnt < k){
            continue;
        }else{
            ans |= (1LL << i);
        }
    }
    cout << ans << endl;
    return 0;
}