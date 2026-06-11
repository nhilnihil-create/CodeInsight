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
string dp[N];
void solve()
{
   string s,t; cin>>s>>t;
   int n=s.size();
   for(int i=0;i<n;i++)dp[i]="";
   for(int i=0;i<t.size();i++)
   {
       for(int j=n-1;j>=0;j--)
       {
           if(s[j]==t[i])
           {
               if(j)dp[j]=dp[j-1]+s[j];
               else dp[j]=s[j];
           }
       }
       for(int j=1;j<n;j++)
           if(dp[j-1].size()>dp[j].size())dp[j]=dp[j-1];
   }
   cout<<dp[n-1];
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
