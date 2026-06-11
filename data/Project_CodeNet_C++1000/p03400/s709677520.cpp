#include<bits/stdc++.h>
using namespace std;

#define int long long int 

int32_t main()
{
    int n;
    cin>>n;
    int x,y;
    cin>>x>>y;
    int a[n];
    int ans=n+y;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=(x-1)/a[i];
       // cout<<ans<<endl;
    }
    cout<<ans<<endl;
    
}