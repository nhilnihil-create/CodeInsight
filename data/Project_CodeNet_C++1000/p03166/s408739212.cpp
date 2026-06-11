    //Abhigyan's Code:
             
    //YOU DON'T DARE TO COPY :) 

    #include<bits/stdc++.h>
    using namespace std;
    typedef long long int ll;
    typedef unsigned long long int ull;
    #define checker cout<<"CHECKED" 
    #define modulo 1000000007
    bool vis[100005] ;

    vector<ll> adj[100005] ;

    void dfs(ll src , vector<ll> &dp)
    {
      vis[src] = true ; 
      for(auto z : adj[src])
      {
        if(!vis[z])
        {
          dfs(z , dp) ;
        }
        dp[src] = max(dp[src] , 1 + dp[z]) ;
      }
    }
  
    int main()
    {
      ios_base::sync_with_stdio(false);
      cin.tie(NULL);
     
      ll n , m ;
      cin >> n  >> m ;

      ll temp = m;

      while(temp--)
      {
        ll x , y ;
        cin >> x >> y;
        adj[x].push_back(y); 
      }
      vector<ll> dp(n+1) ;

      memset(vis , false , sizeof(vis)) ;

      for(ll i = 0 ; i<= n; i++)
        dp[i] = 0 ;
      
      for(ll i =1 ; i <= n ;i++)
      {
        if(!vis[i])
          dfs(i,dp);
      }

      cout << *(max_element(dp.begin() , dp.begin()+n + 1 ) ) <<endl ;

    return 0;

   }   