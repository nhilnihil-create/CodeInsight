 #include<bits/stdc++.h>
 // #include <ext/pb_ds/tree_policy.hpp>
 // #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
 using namespace std;
 using namespace std::chrono;      
 //using namespace __gnu_pbds; 
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

int total[100001] ;
vector<vii> tree,par;

void dfs(int u,int p)
{
   par[p].pb(u);
   
   int bl =1 ,wh=1;
   

   for(auto x:tree[u])
   if(x!=p)
   {
       dfs(x,u);
       wh = (wh%M*total[x]%M)%M;
       for(auto z:par[x]) bl = (bl%M*total[z]%M)%M;
   }


   total[u] = bl+wh;
   total[u]%=M;

}
void solve()
{
   int n;
   cin >> n;
   
   tree.assign(n+1,vii());
   par.assign(n+1,vii());

   forf(i,0,n-1)
   {
    int u,v;
    cin >> u >> v;
    tree[u].pb(v);
    tree[v].pb(u);
   }

   dfs(1,0);
  //forf(i,1,n+1) cout<<total[i]<<" "<<black[i]<<"\n";
   cout<<total[1];
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
      
      