#include<bits/stdc++.h>

using namespace std;

using ll=int64_t;

void factorize(ll n,ll p)
{
    ll ans=1,r=p;
    for(ll i=2;i*i<=p;i++)
    {
        if(r%i==0)
        {
            ll power=0;
            while(r%i==0)
            {
                r/=i;
                ++power;
            }
            power/=n;
            if(power)
            {
                for(ll j=1;j<=power;j++)
                {
                    ans*=i;
                }
            }
        }
    }
    if(n==1)
        ans*=r;

    cout<<ans<<endl;
}

int main()
{
    ll n,p;
    cin>>n>>p;
    factorize(n,p);
}
