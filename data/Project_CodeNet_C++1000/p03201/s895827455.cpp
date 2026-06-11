#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#include<map>
ll ar1[210000];
ll ar2[10000];
ll fun(ll a)
{
    ll i;
    for(i=1; i<=32; i++)
    {
        if(ar2[i]>a)
            return ar2[i];
    }
}
int main()
{
    ll a,b=1,c,d,i,j;
    map<ll,ll>br;
    cin>>a;
    for(i=1; i<=a; i++)
    {
        cin>>ar1[i];
        br[ar1[i]]++;
    }
    sort(ar1+1,ar1+1+a);
    for(i=1; i<=32; i++)
    {
        b=b*2;
        ar2[i]=b;
    }
    ll cnt=0;
    for(i=a; i>=1; i--)
    {
        ll n=fun(ar1[i]);
        ll k=n-ar1[i];
        br[ar1[i]]--;
        if(br[k]>0 && br[ar1[i]]>=0)
        {
            cnt++;
            br[k]--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
