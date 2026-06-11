#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll d,n,ans,i;
    cin>>d>>n;
   // ans=pow(100,d)*n;
    ans=1;
    for(i=0;i<d;i++)
    {
        ans=(ans%ll(1e9+7))*100;
    }
    if(n==100)
    {
        ans=(ans%ll(1e9+7))*(n+1);
        cout<<ans;
    }
    else
    {
        ans=(ans%ll(1e9+7))*n;
        cout<<ans;
    }
    return 0;
}
