#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;


int main()
{
    ll n,ans=0;
    cin>>n;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ll m,x;
            m=i-1;x=n/i;
            if(!m){}
            else if(n/m==x&&n%m==x)ans+=m;

            if(i*i<n)
            {
                m=n/i-1;x=i;
            if(!m){}
            else if(n/m==x&&n%m==x)ans+=m;

            }
        }
    }
    cout<<ans<<endl;

    return 0;
}

