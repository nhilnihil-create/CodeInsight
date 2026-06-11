#include<bits/stdc++.h>
using namespace std;
#define ll long long



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//    ll x;
//    x=1ll << 59;
//    ll y=(1ll << 59) - 1ll;
//    cout<<((double)(x)==(double)(x-1))<<endl;
    ll n;
    cin>>n;
    ll l1[n+1],l2[n+1],sl1[n+1],sl2[n+1];
    sl1[0]=0;
    sl2[0]=0;
    for(int i=1;i<=n;i++){
        cin>>l1[i];
        sl1[i]=sl1[i-1]+l1[i];
    }
    for(int i=1;i<=n;i++){
        cin>>l2[i];
        sl2[i]=sl2[i-1]+l2[i];
    }
    ll s=0;
    for(int i=1;i<=n;i++){
        s=max(s,sl1[i]+sl2[n]-sl2[i-1]);
    }
    cout<<s<<endl;
}
