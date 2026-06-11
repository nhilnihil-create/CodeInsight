        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
const int MAX = 510000;
const int MOD = 1000000007;

     signed main(){
        int n,m,q;
        cin>>n>>m>>q;
        int dp[n][n];
        for(int i=0;i<n;i++)fill(dp[i],dp[i]+n,0);
        int l,r;
        for(int i=0;i<m;i++){
             cin>>l>>r;l--;r--;
             dp[l][r]++;
        }
        for(int i=n-2;i>=0;i--)for(int j=0;j<n;j++)dp[i][j]+=dp[i+1][j];
        for(int i=0;i<n;i++)for(int j=1;j<n;j++)dp[i][j]+=dp[i][j-1];

        for(int i=0;i<q;i++){
             cin>>l>>r;l--;r--;
             cout<<dp[l][r]<<endl;
        }
     }


 


 






    





      

        
