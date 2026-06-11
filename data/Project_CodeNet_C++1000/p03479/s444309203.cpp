/*
        Author: Prokash
                CSE48, JU

*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
int ara[2005];
int main()
{
    FAST;
    ll a,b,n;
    cin>>a>>b;
    ll ans=0;
    while(a<=b)
    {
        a*=2;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}