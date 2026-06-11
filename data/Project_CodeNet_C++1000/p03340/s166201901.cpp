#include<iostream>
#define int long long
using namespace std;
const int maxn=200010;
int n;
int a[maxn];
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int ans=0;
    int l=0,sum=0,yihuo=0;
    for(int i=1;i<=n;i++)
    {
        while(l+1<=n && (yihuo^a[l+1])==(sum+a[l+1]))
        {
            yihuo^=a[l+1];
            sum+=a[l+1];
            l++;
        }
        ans+=l-i+1;
        yihuo^=a[i];
        sum-=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
