#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll k,a,b;cin>>k>>a>>b;

    ll ans=1;

    if(a>=b-1)ans=k+1;
    else for(int i=0;i<k;)
    {
        if(ans<a||i>=k-1)
        {
            ans++;
            i++;
        }
        else
        {
            ans+=b-a;
            i+=2;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
