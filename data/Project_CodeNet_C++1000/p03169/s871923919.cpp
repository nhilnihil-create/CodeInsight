#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[4],o;
double dp[309][309][309],n;
double best(ll x,ll y,ll z)
{
    if(x==0&&y==0&&z==0) return 0;
    double &r=dp[x][y][z],k=x+y+z;
    if(r!=-1)return r;r=0;
    if(x)
    r+=best(x-1,y,z)*x/k;
    if(y)
    r+=best(x+1,y-1,z)*y/k;
    if(z)
    r+=best(x,y+1,z-1)*z/k;
    r+=n/k;
    return r;
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(ll i=0;i<n;i++){
    cin>>o;
    a[o]++;
}
for(ll i=0;i<305;i++)
for(ll j=0;j<305;j++)
for(ll k=0;k<305;k++)
    dp[i][j][k]=-1;
printf("%0.10f",best(a[1],a[2],a[3]));
return 0;
}
