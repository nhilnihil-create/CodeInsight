 #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
 using namespace std;
 using namespace std::chrono;      
 using namespace __gnu_pbds; 
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
 #define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 #define M          1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        3e18
 #define sm         -2e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

//#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
  
void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("gin.txt", "r", stdin);
    freopen("gout.txt", "w", stdout);
   
    #endif
}

int dp[401][401],a[401],cum[401];
void solve()
{
  int n;
  cin >> n;

  forf(i,0,401) forf(j,0,401) dp[i][j] = big;
  forf(i,1,n+1) cin >> a[i],dp[i][i]= 0 ;
  
  
  forf(i,1,n+1)
  {
    cum[i]  = cum[i-1] + a[i];
  }

  
  for(int l=2;l<=n;l++)
  {
    for(int i=1;i<=n-l+1;i++)
    {//i - > i+l-1
      for(int k = i; k<i+l-1 ; k++)
      {

        dp[i][i+l-1] = min(dp[i][i+l-1] , dp[i][k] + dp[k+1][i+l-1] + cum[k] - cum[i-1] + cum[i+l-1] - cum[k]);
      }
    }
  }

  // for(int i=1;i<=n;i++)
  // {
  //   for(int j=1;j<=n;j++) cout<<dp[i][j]<<" ";
  //     cout<<"\n";
  // }

  cout<<dp[1][n];
  
}


int32_t main()
{
  pr_init();
  //fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
   // cout << "Time taken by function: "
   //       << duration.count() << " microseconds" << endl; 

 }
      
      