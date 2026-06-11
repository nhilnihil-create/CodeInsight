//Problem D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll n,x[N],s[N],e[N],a;

int main(){
    scanf("%lld%lld",&n,&a);
    for(ll i=1;i<=n;i++)scanf("%lld",&x[i]),s[i]=x[i]+s[i-1];
    e[1]=e[2]=5;
    for(ll i=3;i<=n;i++)e[i]=e[i-1]+2;
    ll ans=8e18;
    for(ll d=1;d<=n;d++){
        ll x=d*a;
        for(ll i=n,j,c=1;i&&x<ans;i=j,++c){
            j=max(0ll,i-d);
            x+=e[c]*(s[i]-s[j]);
        }
        if(x<ans)ans=x;
    }
    cout<<ans+n*a;
    return 0;
}