#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mx 100009
ll ar[mx][3];
ll mem[mx][3];
ll n;

ll dp(ll ind,ll f){
    if(ind>=n) return 0;
    else if(mem[ind][f]!=-1) return mem[ind][f];

    ll ans=0;
    if(f==0){
        ll x=ar[ind+1][1]+dp(ind+1,1);
        ll y=ar[ind+1][2]+dp(ind+1,2);
        ans=max(x,y);
    }
    else if(f==1){
        ll x=ar[ind+1][0]+dp(ind+1,0);
        ll y=ar[ind+1][2]+dp(ind+1,2);
        ans=max(x,y);
    }
    else{
        ll x=ar[ind+1][1]+dp(ind+1,1);
        ll y=ar[ind+1][0]+dp(ind+1,0);
        ans=max(x,y);
    }
    return mem[ind][f]=ans;
}

int main()
{
    memset(mem,-1,sizeof(mem));
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>ar[i][0]>>ar[i][1]>>ar[i][2];
    }
    ll a=ar[1][0]+dp(1,0);
    ll b=ar[1][1]+dp(1,1);
    ll c=ar[1][2]+dp(1,2);
    cout<<max(a,max(b,c))<<endl;
    return 0;
}
