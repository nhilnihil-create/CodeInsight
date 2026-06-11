#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    ll n,k;cin>>n>>k;

    ll a,ans=0;

    for(a=1;a<=n;a++){
        ans+=(n/a)*max(a-k,0LL);
        ans+=max(n%a+1-k,0LL);
    }

    if(k==0){ans-=n;}//k==0のときは0をaにつき一回余分に数えている

    cout<<ans<<endl;

    return 0;
}