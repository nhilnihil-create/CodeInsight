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
    ios::sync_with_stdio(0);
    //cin.tie(0);

    ll n,k;
    cin>>n>>k;

    int p=0,ans=0;
    for(int i=0; i<n; i++)
    {
        ll x;
        cin>>x;
    }

    for(int i=0; i<n; i++)
    {
        p++;
        if(p==k)
        {
            ans++;
            p=0;
            if(i==n-1)
                break;
            i--;
        }
    }
    if(p)
        ans++;

    cout<<ans<<endl;

    return 0;
}
