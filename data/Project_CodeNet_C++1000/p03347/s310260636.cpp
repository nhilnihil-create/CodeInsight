#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    if(a[0]!=0)return cout<<"-1" , 0;
    for(ll i=0;i<n-1;i++)if(a[i+1]-a[i]>1)return cout<<"-1" , 0;
    ll ans = 0;
    for(ll i=0;i<n;i++){
        if(a[i]==a[i-1]+1)ans++;
        else ans+=a[i];
    }
    cout<<ans;
}
