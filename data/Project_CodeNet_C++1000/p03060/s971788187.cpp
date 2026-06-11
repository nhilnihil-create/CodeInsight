#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>v(n+2),c(n+2),d(n+2);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i];
    }
    for(int i=0;i<n;i++)
    {
        d[i]=v[i]-c[i];
    }
    long long ans=0;
    for(int i=0;i<n;i++)
    {
        if(d[i]>0)
            ans+=d[i];
    }
    cout<<ans<<endl;
}
