#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin>>n;
    map<ll , ll> data;
    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        data[temp]++;
    }
    ll m;
    cin>>m;
    bool exists = true;
    for(int i=0;i<m;i++)
    {
        ll temp;
        cin>>temp;
        if( data[temp] )
        {
            data[temp] --;
        } else
        {
            exists = false;
        }
    }
    if( exists)
    {
        cout<<"YES";
    }
    else cout<<"NO";
}