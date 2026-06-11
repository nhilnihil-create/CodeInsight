#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    int s=0;
    if(n==1)
    {
        cout<<a[0]<<endl;return 0;
    }
    else if(n==2)
    {
        cout<<max(a[0],a[1])<<endl;
        return 0;
    }
    for(int i=0;i<n;i++)s+=a[i];
    sort(a,a+n);
    bitset<4000000>b;
    b[0]=1;
    for(int i=0;i<n;i++)
    {
        b |= (b<<a[i]);
    }
    for(int j=(s+1)/2;j<s;j++)
    {
        if(b[j])
        {
            cout<<j<<endl;
            break;
        }
    }
    return 0;
}
