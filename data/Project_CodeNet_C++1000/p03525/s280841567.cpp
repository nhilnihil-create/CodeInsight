#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int a[52];
    a[0]=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    a[n+1]=24;
    sort(a,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(i&1)
            a[i]=24-a[i];
    }
    sort(a,a+n+1);
    int ans=24;
    for(int i=0;i<=n;i++)
    {
        ans=min(ans,a[i+1]-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}
