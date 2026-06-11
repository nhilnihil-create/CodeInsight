#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
int n;
ll a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    if(a[n]!=2){printf("-1\n");return 0;}
    ll l=2,r=3;
    for(int i=n-1;i>=1;i--)
    {
        ll ans=l/a[i]*a[i];
        if(ans<l) ans+=a[i];
        if(ans>r){printf("-1\n");return 0;}
        ll res=r/a[i]*a[i]+a[i]-1;
        l=ans;r=res;
    }
    printf("%lld %lld\n",l,r);
}
