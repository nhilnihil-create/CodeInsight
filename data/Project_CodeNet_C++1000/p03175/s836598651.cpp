  #include <bits/stdc++.h>
  using namespace std;
  long long MOD=1000000007;
  #define IOS() ios_base::sync_with_stdio(0); cin.tie(0);
  typedef long long ll;
  #define pb push_back
  typedef pair<int,int> pi;
  std::vector<int> g[100010];
  ll dp[100010][2];

ll solve(int node , int constraint , int parent)
{ 
  
   if(dp[node][constraint]!=-1)
    return dp[node][constraint];

  ll ans=0ll;
  ll w1=1ll;



   for(auto child : g[node])
   {
       if(child!=parent)
       {
          w1= ( w1 * solve(child , 0 , node)) %MOD;
       }
   }

   ans=(ans+w1)%MOD;

   if(!constraint)
   {  
    ll w2=1ll;

      for(auto child : g[node])
      {
         if(child!=parent)
         {
            w2= ( w2 * solve(child , 1 , node)) %MOD;
         }
     }

     ans=(ans+w2)%MOD;

   }


   return dp[node][constraint]=ans;

    
}

int main()
{

    int n;
    cin>>n;
    int a,b;
    memset(dp, -1, sizeof dp);

    for (int i = 0; i < n-1; ++i)
    {
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    

    cout<<solve(1,0,-1)<<endl;


    return 0;
    
} 