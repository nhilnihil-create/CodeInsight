  #include <bits/stdc++.h>
  using namespace std;
  long long MOD=1000000007;
  #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
  typedef long long ll;
  #define pb push_back
  typedef pair<int,int> pi;
  int dp[22][1<<22];

  ll solve(std::vector<vector<int>>& compat , int i , int n , int womanset)
  {
      if(i==(n+1) )
      {
        if(womanset==0)
          return 1;
        else
          return 0;

      }

      if(dp[i][womanset]!=-1)
        return dp[i][womanset];


      ll ans=0ll;
      for(int woman=0;woman<n;woman++)
      {
        bool available = (womanset & (1<<woman)) ? 1 : 0 ;
        if(available && compat[i][woman+1])
        {
          ans= ( ans+ solve(compat , i+1 , n , womanset ^ (1<<woman)) ) % MOD;
        }

      }

      return dp[i][womanset]=ans;
  }


int main()
{
    int n;cin>>n;
    std::vector< vector<int> > compat ( n+1 , vector<int> (n+1) );
    std::vector<int> temp;
    int val;
    memset(dp , -1 ,  sizeof dp);
    for(int i=1;i<=n;i++)
    {
     
      for(int j=1;j<=n;j++)
      {
        cin>>compat[i][j];
      }
      
    }


    cout<<solve(compat , 1 , n , (1<<n)-1 )<<endl;
    return 0;
    
} 