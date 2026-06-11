#include<bits/stdc++.h>
using namespace std;

#define FastRead        ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl            "\n"
#define sq(x)           ((x)*(x))
#define pi              acos(-1.0)
#define NUM             1000005

typedef long long ll;


int main()
{
    FastRead

    ll n,x=0,y=0,ans=0;

    cin>>n;

    vector<ll>a(n),b(n);

    for(auto &it:a)
        cin>>it;
    for(auto &it:b)
        cin>>it;

    for(ll i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            x+=a[i];
            y+=b[i];
            ans = max(ans,x-y);
        }
    }

    cout<<ans<<endl;
}
