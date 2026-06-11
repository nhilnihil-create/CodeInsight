#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],ans,sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<n-1;i++)
    {
        sum=sum+a[i];
    }
    ans=sum+a[n-1]/2;
    cout<<ans<<endl;

}
