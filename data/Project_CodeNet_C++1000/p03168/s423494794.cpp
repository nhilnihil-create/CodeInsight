#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define Max 1000
using namespace std;
const int N=3005;
double dp[N],p[N];
double ans;
void solve()
{
   int n; cin>>n;
   for(int i=0;i<n;i++)cin>>p[i];
   dp[0]=1;
   for(int i=0;i<n;i++)
   {
       for(int j=n/2;j>=0;j--)
       {
           if(j)dp[j]=dp[j-1]*(1-p[i])+dp[j]*p[i];
           else dp[j]=dp[j]*p[i];
       }
   }
   for(int i=0;i<=n/2;i++)ans+=dp[i];
   printf("%0.9f",ans);
   return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
