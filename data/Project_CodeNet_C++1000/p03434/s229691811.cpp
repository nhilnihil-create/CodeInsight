#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;

int main()
{
    ll n,a,sum1=0,sum2=0;
    cin>>n;
    vector<ll> v;
    
    for(ll i=0;i<n;i++)
    {
        cin>>a;
        v.push_back(a);
        
    }
	
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(ll i=0;i<n;i++)
    {
        if(i%2==0)
        {
            sum1+=v[i];
        }
        
        else
        {
            sum2+=v[i];
        }
    }
    
    cout<<sum1-sum2;
    
	return 0;
}