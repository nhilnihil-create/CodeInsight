#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll a,b,c;      // un解毒，解毒，毒
    cin>>a>>b>>c;
    ll ans=0;
    if(c>b+a)
    {
        ans=a+b+b+1;
    }
    else
    {
        ans=c+b;
    }
    cout<<ans;
}
