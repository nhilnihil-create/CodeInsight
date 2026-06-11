#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m,c,t;
    scanf("%lld",&n);
    ll a[n+4];
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    } ll g=a[0];
    for(i=1;i<n;i++){
      g=__gcd(g,a[i]);
    } printf("%lld\n",g);
}

