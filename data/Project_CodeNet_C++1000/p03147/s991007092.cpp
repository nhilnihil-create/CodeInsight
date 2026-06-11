#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m,c,t,mn,l,r;
    scanf("%lld",&n);
    ll a[n+4];
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    } ll ans=0;
    while(1){
        mn=LLONG_MAX;l=0;r=n-1;
        bool flag=0;
        for(i=0;i<n;i++){
            if(a[i]==0&&flag){r=i-1;break;}
            if(a[i]&&!flag){flag=1;l=i;}
            if(a[i]) mn=min(mn,a[i]);
        } if(flag==0) break;
        ans+=mn;
        for(i=l;i<=r;i++) a[i]-=mn;
    }
    printf("%lld\n",ans);
}

