#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mx 100009
ll ar[mx+10];
ll mem[mx+10];
ll n;

ll dp(ll ind){
    if(ind>n)  return INT_MAX;
    else if(ind==n) return 0;
    else if(mem[ind]!=-1) return mem[ind];

    ll x=abs(ar[ind]-ar[ind+1])+dp(ind+1);
    ll y=abs(ar[ind]-ar[ind+2])+dp(ind+2);
    mem[ind]=min(x,y);
    return mem[ind];
}

int main()
{

    memset(mem,-1,sizeof(mem));
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>ar[i];
    }
    cout<<dp(1)<<endl;
    return 0;
}
