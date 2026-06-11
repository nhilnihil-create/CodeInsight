#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,ans=0;cin>>n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        ll x,y;cin>>x>>y;
        ans+=x;
        a[i]=x+y;
    }
    sort(a.rbegin(),a.rend());
    for(ll i=1;i<n;i+=2)ans-=a[i];
    cout<<ans;
}