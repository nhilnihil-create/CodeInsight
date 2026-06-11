#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    int ans=INT_MAX;
    for(int i=0;i<=n;i++)
    {
        int t=i;
        int cache=0;
        while(t>0)cache+=t%6,t/=6;
        t=n-i;
        while(t>0)cache+=t%9,t/=9;
        ans=min(ans,cache);
    }
    cout<<ans<<endl;
}