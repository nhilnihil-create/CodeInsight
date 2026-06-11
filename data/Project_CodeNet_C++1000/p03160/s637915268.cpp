
#include<bits/stdc++.h>
#define ll long long int
#define s(l) scanf("%lld",&l)
#define ss(lc) scanf("%s",lc)

#define ppp push_back
#define p(x) printf("%lld\n",x)
#define sr string
#define vr vector
/*int ff(int w)
{
    if(w==1){return 1;}
    else if(w==0){return 1;}
    else{return w*ff(w-1);}
}*/
/*int pr(int ww)
{
    int xs=ww/2;
    int sx=1;
    for(int i=2;i<=xs;i++)
    {
        if(ww%i==0){sx=0;break;}

    }
    return sx;
}*/
ll a[200005],b[200005];
using namespace std;
int main()
{
    vr<ll> mn;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
  ll x=0,y,z=0,zz,i,j,k=0,l,m,n,o,p,q,r,ss;
  s(n);
vr<ll>dp(n,0);
for(i=0;i<n;i++)
{
    s(a[i]);
}
dp[1]=abs(a[1]-a[0]);
for(i=2;i<n;i++)
{
    dp[i]=min(abs(a[i]-a[i-1])+dp[i-1],abs(a[i]-a[i-2])+dp[i-2]);//cout<<dp[i]<<" "<<abs(a[i]-a[i-1])<<dp[i-1]<<abs(a[i]-a[i-2])<<dp[i-2]<<endl;
}
cout<<dp[n-1]<<endl;
}



