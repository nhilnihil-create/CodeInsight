#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
    ll r,g,b,n;
    cin>>r>>g>>b>>n;
    ll ans=0;
    for(int i=0;r*i<=n;i++) {
        ll x=n-r*i;
        for(int j=0; g*j<=x;j++) {
            ll y=x-g*j;
            if(y%b==0){
              ans++;
            }
        }
    }

    cout<<ans<<endl;
}