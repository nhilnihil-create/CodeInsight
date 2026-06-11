#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ios ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);

int main()
{
    ios
    ll n;
    cin>>n;
    vector<ll> v(n);
    ll ct=0,sum=0,ctm=0,mn=1000000000;
    for(ll i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=abs(v[i]);
        if(v[i]<0)
            ctm++;
        if(v[i]==0)
            ct++;
        mn=min(abs(v[i]),mn);
    }
    if(ctm%2==0)
        cout<<sum;
    else if(ctm%2==1 && ct>0)
        cout<<sum;
    else
        cout<<sum-2*mn;
    return 0;
}
