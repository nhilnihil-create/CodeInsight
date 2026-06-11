#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int ar[n+2],a1[n+2],a2[n+2],s;
    for(int i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    a1[0]=0;a2[n+1]=0;
    for(int i=1;i<=n;i++)
    {
        a1[i]=__gcd(a1[i-1],ar[i]);
    }
    for(int i=n;i>=1;i--)
    {
        a2[i]=__gcd(a2[i+1],ar[i]);
    }
    s=0;
    for(int i=1;i<=n;i++)
    {
       s=max(s,__gcd(a1[i-1],a2[i+1]));
    }
    cout<<s<<endl;
}
