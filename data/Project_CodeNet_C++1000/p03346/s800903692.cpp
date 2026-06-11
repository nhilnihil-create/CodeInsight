#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=2e5+5;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n;cin>>n;
    ll p[n];for(ll i=0,x;i<n;i++)cin>>x,p[x-1]=i;
    ll ans=1,cur=1;
    for(ll i=1;i<n;i++){
        if(p[i]>p[i-1])cur++;
        else cur=1;
        ans=max(ans,cur);
    }
    cout<<n-ans<<"\n";
}
