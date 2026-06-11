#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i];
    ll ans = 0;
    for(ll i=0;i<n;i++){
        ll j=i;
        while(j<n && a[j]==a[i])j++;
        ans+=(j-i)/2;
        i=j-1;
    }
    cout<<ans;
}


