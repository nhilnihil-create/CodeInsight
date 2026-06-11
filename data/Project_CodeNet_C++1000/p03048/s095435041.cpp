#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll r,g,b,n,ans=0;
    cin>>r>>g>>b>>n;
    for(ll i=0; i<=n; i++) {
        for(ll j=0; j<=n; j++) {
            ll k = n - r*i - g*j;
            if(n >= r*i + g*j && k % b == 0) ans++;
        }
    }
    cout<<ans;
}