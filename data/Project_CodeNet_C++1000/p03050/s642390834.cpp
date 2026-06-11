#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;

        ll m = (n/i)-1;
        if(m>i)ans+=m;
    }
    cout<<ans;
}



