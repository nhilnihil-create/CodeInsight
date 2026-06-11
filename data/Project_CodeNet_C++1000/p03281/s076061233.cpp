//Radhe Radhe
#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

ll divisor(ll n)
{
    ll i,cnt=0,lim=sqrt(n);
    for(i=1; i<=lim; i++)
    {
        if(n%i==0)
        {
            if(n/i==i)
                cnt++;
            else
                cnt+=2;
        }
    }
    return cnt;
}

int main()
{
    fast_io
    ll i,j,n,ans=0;
    cin>>n;
    for(i=1; i<=n; i+=2)
    {
        ll x=divisor(i);
        if(x==8){
           // cout<<i<<" "<<x<<endl;
            ans++;
        }
    }

    cout<<ans<<endl;




    return 0;
}



