#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll direction[8][2]={{1,0},{0,1},{0,-1},{-1,0},{-1,1},{-1,-1},{1,-1},{1,1}};
bool valid(ll a,ll b){
    if(a>=1&&a<=n&&b>=1&&b<=m)return true;
    else return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll x=0;
    cin>>n>>m;
    ll c=n,d=m;
    n=min(c,d);
    m=max(c,d);
    if(n==1&&m==1)cout<<1<<endl;
    else if(n==1)cout<<m-2<<endl;
    else cout<<(ll)((ll)(n*m)-(ll)(2ll*n)-(ll)(2ll*m)+4ll)<<endl;
}
