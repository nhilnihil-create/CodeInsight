#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    ll a[n+1];for(ll i=1;i<=n;i++)cin>>a[i];
    ll l=2,r=2;
    for(ll i=n;i>=1;i--){
        ll nl =( (l+a[i]-1)/a[i] )*a[i];
        ll nr =( r/a[i] )*a[i];
        if(nl>nr)return cout<<"-1" , 0;
        l=nl;
        r=nr+a[i]-1;
    }
    cout<<l<<" "<<r;
}