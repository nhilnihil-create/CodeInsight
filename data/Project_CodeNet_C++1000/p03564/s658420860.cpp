#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    ll n,k;
    cin>>n>>k;
    ll ans=1;
    for(int i=0;i<n;i++){
        if(ans<=k){
            ans=ans*2;
        }else{
            ans+=k;
        }
    }
    cout<<ans<<endl;
    
}
