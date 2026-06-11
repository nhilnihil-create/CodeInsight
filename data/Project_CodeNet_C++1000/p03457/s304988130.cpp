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
    ll t[n+1],x[n+1],y[n+1];t[0]=0,x[0]=0,y[0]=0;ll d=0;
    for(int i=1;i<=n;i++){
        cin>>t[i]>>x[i]>>y[i];
        ll a=t[i]-t[i-1],b=abs(x[i]-x[i-1]),c=abs(y[i]-y[i-1]);
        if(b+c==a);
        else if(a>(b+c)&& (a-b-c)%2==0);
        else{
            d=2;break;
        }
    }
    if(d==2)cout<<"No";
    else cout<<"Yes";
}
