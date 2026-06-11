#include<bits/stdc++.h>
using namespace std;
const int t=1e7;
long long a[t],b[t];
int n;
long long sum,spfa;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) 
    {
        cin>>b[i];
    }
    for(int i=1;i<=n;i++) 
    {
        if(a[i]>b[i]) 
        {
            sum+=(a[i]-b[i]);
        }
        if(a[i]<b[i]) 
        {
            spfa+=(b[i]-a[i])/2;
        }
    }
    if(sum<=spfa) cout<<"Yes";
    else cout<<"No";
    return 0;
}