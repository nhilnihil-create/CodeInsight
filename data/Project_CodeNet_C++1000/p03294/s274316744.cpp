#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll n,ans=0,i;
    ll a[100000];
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i]-1;
    }
    cout<<ans;
    return 0;
}
