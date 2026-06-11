#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll m,k;cin>>m>>k;
    if(k>=(1ll<<m))return cout<<"-1" , 0;
    if(m==1){
        if(k==0)cout<<"0 1 1 0";
        else cout<<"-1";
        return 0;
    }
    for(ll i=0;i<=(1ll<<m)-1;i++)if(i!=k)cout<<i<<" ";
    cout<<k<<" ";
    for(ll i=(1ll<<m)-1;i>=0;i--)if(i!=k)cout<<i<<" ";
    cout<<k;
}