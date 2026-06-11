#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll n,i,j,k,l,a,b,c,d,s;
    cin>>n;
    vector<ll>u,v;
    v.push_back(0);
    for(i=0;i<n;i++)
    {
        cin>>k;
        v.push_back(k);
    }
    v.push_back(0);
    s=0;
    for(i=1;i<=n+1;i++)
    {
        s+=abs(v[i]-v[i-1]);
    }

    for(i=1;i<n+1;i++)
    {
        c=s;
        c-=abs(v[i]-v[i-1]);
        c-=abs(v[i+1]-v[i]);
        c+=abs(v[i+1]-v[i-1]);
        cout<<c<<endl;
    }
    return 0;
}
