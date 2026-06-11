#include<bits/stdc++.h>
#define     fast                    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define     ll                      long long
#define     pb                      push_back
#define     M                       1000000007
using namespace std;
int main()
{
    ll n,x,sum=0;
    vector<ll>v;
    for(ll i=0; i<3; i++)
    {
        cin>>x;
        v.pb(x);
    }
    sort(v.begin(),v.end());
    for(ll i=0; i<v.size()-1; i++)
    {
        sum+=(v[i+1]-v[i]);
    }
    cout<<sum<<endl;

}
