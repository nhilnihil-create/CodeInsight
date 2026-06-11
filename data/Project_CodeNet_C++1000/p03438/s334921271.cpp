#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n,as=0,bs=0;cin>>n;
    ll a[n];for(ll i=0;i<n;i++)cin>>a[i],as+=a[i];
    ll b[n];for(ll i=0;i<n;i++)cin>>b[i],bs+=b[i];
    if(as>bs)return cout<<"No" , 0;
    ll x=0,y=0;
    for(ll i=0;i<n;i++){
        if(a[i]<b[i])y+=(b[i]-a[i]+1)/2;
        else x+=a[i]-b[i];
    }
    if(x<=(bs-as) && y<=(bs-as))cout<<"Yes";
    else cout<<"No";
}