#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
    ll N,K;
    cin>>N>>K;
    ll ans=1;
    for(ll i=0;i<N;i++) {
        ans=min(ans*2,ans+K);
    }

    cout<<ans<<endl;

    }