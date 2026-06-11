#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define m3(a, b, c) min(c, min(a, b))
#define m4(a, b, c, d) min(d, min(c, min(a, b)))
#define test long long t; cin>>t; while(t--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
const ll maxn=1e16+100;
 


 int main()
 {  IOS;
   ll n;
   cin>>n;
   ll a[n];
   for(auto &i:a) cin>>i;
vector<ll>dp(n,maxn);
dp[0]=0;

for(int i=0;i<n;i++)
{
    for(int j=i+1;j<=i+2;j++)
    {
        if(j<n)
        {  
            dp[j]=min(dp[j],dp[i]+abs(a[i]-a[j]));
        }
    }
}
cout<<dp[n-1];
   
 }