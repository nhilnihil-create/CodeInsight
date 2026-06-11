#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m=1,t,y,mx,x,g;
    scanf("%lld",&n);
    ll a[n+3],b[n+3],c[n+3];
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    } b[1]=a[1],c[n]=a[n];
    for(i=2;i<=n;i++) b[i]=__gcd(b[i-1],a[i]);
    for(i=n-1;i>=0;i--) c[i]=__gcd(c[i+1],a[i]);
    mx=max(c[2],b[n-1]);
    for(i=2;i<n;i++){
        mx=max(mx,__gcd(b[i-1],c[i+1]));
    } cout<<mx;
}
