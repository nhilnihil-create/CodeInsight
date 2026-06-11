#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;


int main(void){
    ll n, k;
    cin>>n>>k;
    ll ans=0;
    for(ll i=n-1;i>=k;i--){
        /*余りがiとする*/
        int now=(n-i)/(i+1)+1;
        int div=(n-i)%(i+1);
        ans+=(i-k+1)*now;
        ans+=max(div-k, 0LL);
        //cout<<now<<" "<<div<<endl;
    }
    if(k==0) ans-=n;
    cout<<ans<<endl;
    return 0;

}

