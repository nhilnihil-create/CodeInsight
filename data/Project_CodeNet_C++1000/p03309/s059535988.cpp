#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,x=0;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]-=i+1;
    }
    sort(a,a+n);
    for(ll i=0;i<n;i++)
    {
         x+=abs(a[i]-(a[n/2]));
    }
    cout<<x;

}
