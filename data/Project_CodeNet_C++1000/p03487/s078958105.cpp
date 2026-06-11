#include<bits/stdc++.h>
using namespace std;

#define int long long int

int32_t main()
{
    int n;
    cin>>n;
    map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        m[x]++;
    }
 
    for(auto i:m)
    {
        if(i.first!=i.second)
        ans+=i.second<i.first?i.second:i.second-i.first;
    }
    cout<<ans<<endl;
}