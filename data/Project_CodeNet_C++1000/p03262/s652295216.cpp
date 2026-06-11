#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,x;
    cin>>n>>x;
    vector<ll>v;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n;i++)
    {
        v[i]=abs(v[i]-x);
    }
    ll g=0;
    for(int i=0;i<n;i++)
        g=__gcd(g,v[i]);
    cout<<g<<endl;
    return 0;
}