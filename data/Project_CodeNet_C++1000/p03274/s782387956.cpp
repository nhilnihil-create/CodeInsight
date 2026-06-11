#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n,k;
ll x[100005];
ll ans=10000000000000000;
int main(void){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int l=0;l<=n-k;l++){
        int r=l+k-1;
        if(x[r]<=0){
            ans=min(ans,x[l]*(-1));
        }else if(x[l]>=0){
            ans=min(ans,x[r]);
        }else{
            ans=min(ans,x[r]+x[l]*(-2));
            ans=min(ans,x[r]*2+x[l]*(-1));
        }
    }
    cout<<ans<<endl;
    
}
