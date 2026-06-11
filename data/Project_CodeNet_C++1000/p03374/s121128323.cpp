#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
const int N=1e5+5;
int n;
LL c;
LL x[N],v[N],a[N],b[N];
int main()
{
    cin>>n>>c;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>v[i];
    }
    x[n+1]=c;
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+v[i]-(x[i]-x[i-1]);
        b[n-i+1]=b[n-i+2]+v[n-i+1]-(x[n-i+2]-x[n-i+1]);
    }
    for(int i=2;i<=n;i++)
    {
        a[i]=max(a[i],a[i-1]);
        b[n-i+1]=max(b[n-i+1],b[n-i+2]);
    }
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,a[i]);
        ans=max(ans,b[i]);
        ans=max(ans,a[i]-x[i]+b[i+1]);
        ans=max(ans,b[i]-(c-x[i])+a[i-1]);
    }
    cout<<ans<<endl;
    return 0;
}
