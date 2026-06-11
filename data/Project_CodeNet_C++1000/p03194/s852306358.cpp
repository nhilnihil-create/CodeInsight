#include<bits/stdc++.h>

using namespace std;

using ll=int64_t;

ll pow_expo(ll a,ll b)
{

    ll res=1;
    while(b>0)
    {
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
return res;
}

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
               ans*=pow_expo(i,power);
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
