#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;

ll mod=998244353;

int main(){
    ll n;
    cin>>n;
    
    map<ll,ll> m;
    for(ll i=1;i<=n;++i){
        ll t;
        cin>>t;
        m[t]++;
    }
    ll cnt=0;
    cin>>cnt;
    for(ll i=0;i<cnt;++i){
        ll t;
        cin>>t;
        if(!m[t]){
            cout<<"NO";
            return 0;
        }
        m[t]--;
    }
    cout<<"YES";
}