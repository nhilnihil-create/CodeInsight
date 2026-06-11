#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin>>n;

    if(n==1)
    {
        cout<<1;
        return 0;
    }

    ll bans=1;
    ll ans=3;

    for(int i=2;i<n;i++)
    {
        ans=ans+bans;
        bans=ans-bans;
    }

    cout<<ans<<"\n";

    return 0;
}
