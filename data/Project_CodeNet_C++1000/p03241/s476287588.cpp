#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
vector<ll>div(ll n){
    vector<ll>res;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            ll j=n/i;
            if(j!=i) res.push_back(j);
        }
    }
    sort(res.begin(),res.end());
    return res;
}
int main() {
    ll n,m;
    cin >> n >> m;
    ll ans=1;
    vector<ll>num=div(m);
    for(auto x:num){
        if(x*n<=m) ans=max(ans,x);
    }
    cout << ans << endl;
}