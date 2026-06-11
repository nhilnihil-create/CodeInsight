#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+100;
ll a[maxn];
ll b[maxn];
ll aa[40][maxn],bb[40][maxn];
ll n;
ll ans[40];
ll p;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    p=0;
    for(int i=0;i<30;i++){
        p=p<<1;
        p+=1;
        for(int j=0;j<n;j++){
            aa[i][j]=a[j]&p;
            bb[i][j]=b[j]&p;
        }
        sort(aa[i],aa[i]+n);
        sort(bb[i],bb[i]+n);
    }
    ll mod=1;
    for(int i=0;i<30;i++){
        for(int j=0;j<n;j++){
            ll now=aa[i][j];
            ll l,r;
            l=mod-now;
            r=mod*2-now;
            ans[i]+=(lower_bound(bb[i],bb[i]+n,r)-bb[i])-(lower_bound(bb[i],bb[i]+n,l)-bb[i]);
            l=mod*3-now;
            r=mod*4-now;
            ans[i]+=(lower_bound(bb[i],bb[i]+n,r)-bb[i])-(lower_bound(bb[i],bb[i]+n,l)-bb[i]);
        }
        mod=mod<<1;
    }
    ll k=0;
    for(int i=30;i>=0;i--){
        k=k<<1;
        if(ans[i]%2==1)k+=1;
    }
    cout<<k<<endl;
    return 0;
}
