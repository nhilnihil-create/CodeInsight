#include<bits/stdc++.h>
#define ll long long
const int N=100005;
using namespace std;
ll c[2010],n,z,w;
int main(){
    cin>>n>>z>>w;
    for(int i=0;i<n;i++) cin>>c[i];
    ll ans=abs(c[n-1]-w);
    if(n>1) ans=max(ans,abs(c[n-1]-c[n-2]));
    cout<<ans;
    return 0;
}