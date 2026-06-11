#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
double dp[3009][3009],a[3009];
double best(ll d,ll sum)
{
    if(d==n){
        if(sum>n/2)
        return 1;
        return 0;
    }
    double &r=dp[d][sum];
    if(r!=10) return r;
    return r=(best(d+1,sum)*(double(1)-a[d]))+(best(d+1,sum+1)*a[d]);
}
int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
for(ll i=0;i<n;i++)
    cin>>a[i];
for(ll i=0;i<3005;i++)
    for(ll j=0;j<3005;j++)
    dp[i][j]=10;
printf("%0.10f",best(0,0));
return 0;
}
