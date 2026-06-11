#include<bits/stdc++.h>
using namespace std;
using ll =long long;


int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>v;

    for(ll i=1;i*i<=k;i++)
    {
        if(k%i==0)
        {
            v.push_back(i);
            if(k/i!=i)v.push_back(k/i);
        }
    }

    ll counter;

    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++)
    {
        if(k/v[i]>=n)counter=v[i];
    }
    cout<<counter<<endl;
}
