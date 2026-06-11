#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,mx=-1,i,a[200],j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            mx=max(mx,abs(a[i]-a[j]));
        }
    }
    cout<<mx<<endl;
}
