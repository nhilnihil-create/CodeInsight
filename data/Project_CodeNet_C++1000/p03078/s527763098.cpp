#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    ll a[x],b[y],c[z];
    for(ll i=0;i<x;i++)
    {
        cin>>a[i];
    }
    for(ll i=0;i<y;i++)
    {
        cin>>b[i];
    }
    for(ll i=0;i<z;i++)
    {
        cin>>c[i];
    }
    vector<ll>max2;
    for(ll i=0;i<x;i++)
    {
        for(ll j=0;j<y;j++)
        {
            max2.push_back(a[i]+b[j]);
        }
    }
    sort(max2.begin(),max2.end(),greater<ll>());
    for(ll i=0;i<max2.size();i++)
    {
      //  cout<<max2[i]<<" ";
    }
    //cout<<endl;
    vector<ll>max3;
    ll maxi=min(k,(ll)max2.size());
    for(ll i=0;i<maxi;i++)
    {
        for(ll j=0;j<z;j++)
        {
            max3.push_back(max2[i]+c[j]);
        }
    }
    sort(max3.begin(),max3.end(),greater<ll>());
    for(ll i=0;i<k;i++)
    {
        cout<<max3[i]<<" ";
    }
	return 0;
}
