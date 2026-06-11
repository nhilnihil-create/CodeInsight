#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define mod 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
#define int long long


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   string s,t;
   cin>>s>>t;
   vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));
   for(int i=1;i<=s.size();i++)
   {
       for(int j=1;j<=t.size();j++)
       {
          if(s[i-1]==t[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
          else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
       }
   }
   int i=s.size(),j=t.size();
   vector<char>ans;
   while(i>0 && j>0)
   {
       if(s[i-1]==t[j-1])
       {
         ans.push_back(s[i-1]);
         i--;
         j--;
         continue;
       }
       if(dp[i-1][j]>dp[i][j-1])
       {
           i--;
       }
       else
        j--;

   }
   reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
        cout<<ans[i];

    return 0;
}
