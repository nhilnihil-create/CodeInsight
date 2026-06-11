#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll k,a,b;cin>>k>>a>>b;

    ll ans=1;
    if(k<a)ans+=k;
    else if(b-a>2) 
    {
        ans+=a-1;
        k-=a-1;
        ans+=(b-a)*(k/2)+(k%2);
    }
    else
    {
        ans+=k;
    }

    cout<<ans<<"\n";    

    return 0;
}
