#include<bits/stdc++.h>
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
using namespace std;

int main()
{
    fast_io
    ll n,k,i,j;
    double ans=0,d;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        d=1/(1.0*n);
    for(j=i;j<k;j*=2)
    {
        d*=0.5;
    }
    ans+=d;
    }
    cout.setf(ios::fixed);
    cout.precision(12);

    cout<<ans<<endl;


    return 0;
}



