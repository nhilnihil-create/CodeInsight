#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,h,w,ans=0;
    scanf("%lld%lld%lld",&n,&h,&w);
    for(int i=0;i<n;i++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a/h>=1&&b/w>=1)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
