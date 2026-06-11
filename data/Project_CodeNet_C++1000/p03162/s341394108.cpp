#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define m3(a, b, c) min(c, min(a, b))
#define m4(a, b, c, d) min(d, min(c, min(a, b)))
#define test long long t; cin>>t; while(t--)
#define IOS ios::sync_with_stdio(0);cin.tie(0);
const int maxn=1e6+100;


 int main()
 {
   int n;
   cin>>n;
   vector<vector<int>>a(n,vector<int>(3));
    vector<vector<int>>dp(n,vector<int>(3));
    
    for(int i=0;i<n;i++)
    for(int j=0;j<3;j++)
    cin>>a[i][j];
   
   dp[0]=a[0];
   
   for(int i=1;i<n;i++)
   for(int j=0;j<3;j++)
   for(int k=0;k<3;k++)
   {
       if(j!=k)
       {
           dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
       }
   }
  
   int ma=*max_element(dp[n-1].begin(),dp[n-1].end());
   cout<<ma;
 }