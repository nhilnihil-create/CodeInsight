#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#define debug(x) cout << #x << ": " << x << endl
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
const int MAXN=2e5+7;
const int INF=0x3f3f3f3f;
const int MOD=1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            if(i<(n/i-1))
            {
                ans+=n/i-1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
