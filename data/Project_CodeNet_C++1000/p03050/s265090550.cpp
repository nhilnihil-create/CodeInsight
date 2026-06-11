#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long ll;
const int maxn=1e5+10;
const ll mm=1e9+7;
int main()
{
    ll ans=0;
    ll n;
    cin>>n;
    if(n==2)cout<<0<<endl;
    else{
    for(ll i=1;i*i<n;++i)
    {
        ll now=(n-i)%i;
        if(now==0)
        {
            if(i<(n-i)/i)
            ans=ans+((n-i)/i);
        }
    }
    cout<<ans<<endl;
    }
    return 0;
}
