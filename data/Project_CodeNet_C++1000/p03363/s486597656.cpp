#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n;
    cin >> n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++){
        cin >> a[i];
    }
    for(ll i=1;i<n;i++){
        a[i]+=a[i-1];
    }
    map<ll,ll>data;
    for(ll i=0;i<n;i++){
        data[a[i]]++;
    }
    data[0]++;
    ll ans=0;
    for(auto it:data){
        ll num=it.second;
        ans+=num*(num-1)/2;
    }
    cout << ans << endl;
}