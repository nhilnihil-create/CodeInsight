#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    cin >> n >> m;
    ll a[n];
    ll b[n+1];
    b[0]=0;
    map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        b[i+1]=b[i]+a[i];
        b[i+1]%=m;
    }
    for(ll i=0;i<=n;i++){
        mp[b[i]]++;
    }
    ll res=0;
    for(auto p:mp){
        res+=p.second*(p.second-1)/2;
    }
    cout << res << endl;
}
