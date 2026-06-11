#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin>>n;
    map<ll,ll>mp;
    ll x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mp[x]++;
    }
    int cnt=0;
    for(auto m : mp)
    {
        if(m.first!=m.second)
        {
            if(m.first>m.second)
                cnt+=m.second;
            else
                cnt+=(m.second-m.first);
        }

    }
    cout<<cnt;
}
