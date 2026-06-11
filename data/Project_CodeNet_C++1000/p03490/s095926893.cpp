#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define db long double
#define ii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define SET(A, val) memset(A, val, sizeof(A))
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set ;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N=10005;
vi x1,y2;
int dp1[2][4*N],dp2[2][4*N];
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  string s;
  int x,y;
  cin>>s>>x>>y;
  s+="T";
  while(sz(s) && s[0]=='F')
    s.erase(s.begin()),x--;
  int cnt=0,side=1;
  rep(i,0,sz(s))
    {
      if(s[i]=='T')
	{
	  if(cnt)
	    {
	      if(side) x1.pb(cnt);
	      else y2.pb(cnt);
	    }
	  side=1-side;
	  cnt=0;
	}
      else cnt++;
    }
  dp1[0][N]=1;
  int bit1=1;
  for(auto it:x1)
    {
      rep(i,-N,N)
	if(dp1[1-bit1][i+N])
	  dp1[bit1][i+it+N]=dp1[bit1][i-it+N]=1;
      rep(i,0,4*N)
	dp1[1-bit1][i]=0;
      bit1=1-bit1;
    }
  int bit2=1;
  dp2[0][N]=1;
  for(auto it:y2)
    {
      rep(i,-N,N)
	if(dp2[1-bit2][i+N])
	  dp2[bit2][i+it+N]=dp2[bit2][i-it+N]=1;
      rep(i,0,4*N)
	dp2[1-bit2][i]=0;
      bit2=1-bit2;
    }
  if(dp1[1-bit1][x+N] && dp2[1-bit2][y+N])
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
  return 0 ;
}
