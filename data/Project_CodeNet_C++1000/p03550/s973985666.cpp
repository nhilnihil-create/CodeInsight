#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[2005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll z,w;cin>>n>>z>>w;
    for(ll i=1;i<=n;i++)cin>>a[i];
    if(n==1)return cout<<abs(a[1]-w) , 0;
    cout<<max(abs(a[n]-w),abs(a[n-1]-a[n]));
}

