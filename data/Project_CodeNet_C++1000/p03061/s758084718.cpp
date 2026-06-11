#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,ans=0;
    cin>>n;
    int a[n],b[n+1],c[n+1];
    for( i=0;i<n;i++)
    {
        cin>>a[i];
    }
    b[0]=0;
    for(i=0;i<n;i++)
    {
        b[i+1]=__gcd(b[i],a[i]);
    }
    c[n]=0;
    for(i=n-1;i>=0;i--)
    {
        c[i]=__gcd(c[i+1],a[i]);
    }
    for(i=n-1;i>=0;i--)
    {
    ans=max(ans,__gcd(b[i],c[i+1]));
    }
    cout<<ans;
}
