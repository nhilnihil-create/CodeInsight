#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define pb push_back
#define pii pair<ll,ll>
#define ff first
#define ss second
#define mxx 100005
#define endl "\n"
const ll mod=1e9+7;

int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    while(n--)
    {
        ll x;
        cin>>x;
        if(x%2==0)
        {
            for(ll i=30; i>=1; i--)
            {
                ll a=(ll)pow(2,i);
                if(a<=x)
                {
                    if(x%a==0)
                    {
                        //cout<<x<<" "<<a<<endl;
                        ans+=i;
                        x/=a;
                        if(x%2!=0)
                            break;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}
