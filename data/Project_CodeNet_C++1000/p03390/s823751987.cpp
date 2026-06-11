#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool chk(ll a,ll b,ll k){
    if(b+k>=a*b)return 0;
    if(k*(b+1)>=a*b)return 0;
    if(b+k+1>=2*k)return 1;
    if((b+k+1)*(b+k+1)<4*a*b)return 1;
    return 0;
}
void solve(){
    ll a,b;cin>>a>>b;
    if(a<b)swap(a,b);
    ll s=1,e=a-1,ans=0;
    while(s<=e){
        ll mid=(s+e)>>1;
        if(chk(a,b,mid))ans=mid,s=mid+1;
        else e=mid-1;
    }
    cout<<ans+b-1<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)solve();
}