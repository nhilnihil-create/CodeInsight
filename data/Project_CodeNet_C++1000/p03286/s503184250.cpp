#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mul(ll a, ll b){
    // return ((a%mod) * (b%mod))%mod;
    return a*b;
}
ll power(ll a, ll b){
    ll z = 1; ll x = a;
    while(b>0){
        if (b&1)z = mul(z, x);
        x = mul(x, x);
        b >>= 1;
    }
    return z;
}
int main()
{
    ll n; cin>>n;
    vector<ll> pos, neg;
    ll x = 1, ans = 0;
    for (int i=0; i<20 ;i++){
        ans += x;
        x*=4;
        pos.push_back(ans);
    }
    x = 2, ans = 0;
    for (int i=0; i<20; i++){
        ans += x;
        x*=4;
        neg.push_back(ans);
    }
    vector<ll> res(60);
    ll req = n;
    while(req != 0){
        if (req > 0){
            ll idx = lower_bound(pos.begin(), pos.end(), req) - pos.begin();
            res[2*idx] = 1;
            req -= power(2, 2*idx);
        }
        else{
            ll idx = lower_bound(neg.begin(), neg.end(), abs(req)) - neg.begin();
            res[2*idx+1] = 1;
            req += power(2, 2*idx+1);
        }
    }
    ll e;
    for (int i=59; i>=0; i--)if (res[i]==1){
        e = i;break;
    }
    for (int i=e; i>=0; i--)cout<<res[i];
}