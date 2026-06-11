    #include<bits/stdc++.h> 
    #define ll long long
    #define pb push_back
    #define ld double
    using namespace std;
     
    const int mod = 1e9+7;
     
     
     
     
    int main(){
       int n,k;
      cin>>n>>k;
      vector<int> arr(n);
      for(int i=0;i<n;i++)
      cin>>arr[i];
      int dp[n+2][k+1];
      memset(dp,0,sizeof(dp));
     
      for(int i=0;i<=k && i<=arr[0];i++)
        dp[1][i]=1;
      
      for(int i=2;i<=n;i++){
        for(int j=0;j<=k;j++){
          dp[i][j]= dp[i-1][j]%mod;
          if(j-1>=0)
            dp[i][j]=(dp[i][j] + dp[i][j-1])%mod;
          if(j-1 - arr[i-1] >=0)
            dp[i][j]=(dp[i][j]-dp[i-1][j-1-arr[i-1]]+mod)%mod;
        }
      }
      /*for(int i=1;i<=n;i++)
      {for(int j=0;j<=k;j++)
        cout<<dp[i][j]<<" ";
       cout<<"\n";
      }*/
      cout<<dp[n][k]<<"\n";
    return 0; 
    }