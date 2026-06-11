#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,sum=0;
    cin>>n>>m;
    m=n+1-m;
    int a[n],i,b[n+1];
    for(i=0;i<=n;i++)
    b[i]=0;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
    {
        int k=a[i];
        b[k]++;
    }
    sort(b,b+n+1);
    for(i=0;i<m;i++)
   sum=sum+b[i];

    cout<<sum<<endl;
    return 0;
}

