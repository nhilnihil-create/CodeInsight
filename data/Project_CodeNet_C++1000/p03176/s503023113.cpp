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
 //#define M          1000000007
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


const int Mxn = 200005;

int h[Mxn] , a[Mxn],n;
struct SegTree
{
  int N;
  vector<int> st;
  vector<bool> cLazy;
  vector<int> lazy;

  void init(int n)
  {
    N = n;
    st.resize(4 * N + 5,0);
    cLazy.assign(4 * N + 5, false);
    lazy.assign(4 * N + 5, 0);
  }

  //Write reqd merge functions
  void merge(int &cur, int &l, int &r) 
  {
    cur = max(l, r);
  }

  void propagate(int node, int L, int R)
  {
    if(L != R)
    {
      cLazy[node*2] = 1;
      cLazy[node*2 + 1] = 1;
      lazy[node*2] = lazy[node];
      lazy[node*2 + 1] = lazy[node]; 
    }
    st[node] = lazy[node];
    cLazy[node] = 0;
  }

  void build(int node, int L, int R)
  {
    if(L==R)
    {
      //build some stuff here
      st[node] = 0;
      return;
    }
    int M=(L + R)/2;
    build(node*2, L, M);
    build(node*2 + 1, M + 1, R);
    merge(st[node], st[node*2], st[node*2+1]);
  }

  int Query(int node, int L, int R, int i, int j)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(j<L || i>R)
      return 0;
    if(i<=L && R<=j)
      return st[node];
    int M = (L + R)/2;
    int left=Query(node*2, L, M, i, j);
    int right=Query(node*2 + 1, M + 1, R, i, j);
    int  cur;
    merge(cur, left, right);
    return cur;
  }


  void Update(int node, int L, int R, int i, int j, int val)
  {
    if(cLazy[node])
      propagate(node, L, R);
    if(j<L || i>R)
      return;
    if(i<=L && R<=j)
    {
      cLazy[node] = 1;
      lazy[node] = val;
      propagate(node, L, R);
      return;
    }
    int M = (L + R)/2;
    Update(node*2, L, M, i, j, val);
    Update(node*2 + 1, M + 1, R, i, j, val);
    merge(st[node], st[node*2], st[node*2 + 1]);
  }



  int query(int l, int r)
  {
    return Query(1, 1, N, l, r);
  }


  void update(int l, int r, int val)
  {
    Update(1, 1, N, l, r, val);
  }
};


void solve()
{
 
  cin >> n ;

  forf(i,1,n+1) cin >> h[i];

  forf(i,1,n+1) cin >> a[i];
  
  SegTree My_tree;
  My_tree.init(Mxn);
 
  
  int an = -1;
  forf(i,1,n+1)
  {
    int vl = My_tree.query(0,h[i]-1);
    My_tree.update(h[i],h[i],vl+a[i]);
    an = max(an,vl+a[i]);
  
  }
  
  //cout<<My_tree.query(0,5);
  cout<<an<<"\n";
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
      
      