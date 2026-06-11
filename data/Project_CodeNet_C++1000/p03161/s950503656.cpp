#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mx 100009
ll ar[mx+10];
ll mem[mx+10];
ll n,k;

ll dp(ll ind){
    if(ind>n)  return INT_MAX;
    else if(ind==n) return 0;
    else if(mem[ind]!=-1) return mem[ind];

    ll ans=INT_MAX;
    for(ll i=1;i<=k;i++){
        if(i+ind<=n){
            ll x=abs(ar[ind]-ar[ind+i])+dp(ind+i);
            ans=min(ans,x);
        }
    }
    mem[ind]=ans;
    return mem[ind];
}

int main()
{

    memset(mem,-1,sizeof(mem));
    cin>>n>>k;
    for(ll i=1;i<=n;i++){
        cin>>ar[i];
    }
    cout<<dp(1)<<endl;
    return 0;
}

