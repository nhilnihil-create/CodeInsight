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


int n,k,a[101],dp[101][100001],cum[101][100001];
//cin >> n >> k ;
void solve()
{
   cin >> n >> k;

   forf(i,1,n+1) cin >> a[i];
   

   for(int j=0;j<=k;j++)
     {
      cum[0][j] = 1;
     }

   forf(i,1,n+1)
   {
     for(int j=0;j<=k;j++)
     {
        int id = max((int)0,j-a[i]);

        int vl = cum[i-1][j] - (id>=1?cum[i-1][id-1]:0);
        vl = (vl+M)%M;
        dp[i][j] += vl;
        dp[i][j] %= M;
     }
     cum[i][0] = dp[i][0]%M;

     for(int j=1;j<=k;j++)
     {
      cum[i][j] = dp[i][j]+cum[i][j-1];
      cum[i][j]%=M;
     }

   }
   
   // forf(i,1,n+1)
   // {
   //  forf(j,0,k+1) cout<<dp[i][j]<<" ";
   //  cout<<"\n";
   // }
   
   cout<<dp[n][k]%M;
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
      
      