#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5;
int n;
ll x;
ll a[maxn+10];
int main()
{
    while(cin>>n>>x)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            a[i]+=a[i-1];
        }
        ll ans=1e18;
        for(int k=1;k<=n;k++)
        {
            ll sum=0;
            ll res=3ll;
            for(int i=n;i>=1;i-=k)
            {
                sum=sum+(a[i]-a[max(i-k,0)])*max(res,5ll);
                res+=2;
                if(sum>=ans)
                    break;
            }
            ans=min(ans,sum+x*(n+k));
        }
        cout<<ans<<endl;
    }
    return 0;
}
