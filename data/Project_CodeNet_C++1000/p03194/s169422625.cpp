#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,h,w;
int H,W;
int main()
{
    ll n,p;
    cin>>n>>p;

    ll ans=1;
    for(ll i=2,sq=sqrt(p+0.5);i<=sq;i++)if(p%i==0)
    {
        int cnt=0;
        while(p%i==0)p/=i,cnt++;
        for(int j=cnt/n;j>=1;j--)ans*=i;
    }
    if(p>1)for(int j=1/n;j>=1;j--)ans*=p;
    cout<<ans<<endl;
}
