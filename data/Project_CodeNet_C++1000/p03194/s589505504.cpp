#include <bits/stdc++.h>
 using namespace std;
#define FIO                     ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mod                     1000000007
#define eps                     1e-9
#define setbits                 __builtin_popcount
#define gcd                     __gcd
#define rep(i,a,b)              for(int i=a;i<=b;i++)
#define repr(i,b,a)             for(int i=b;i>=a;i--)
#define forn(i,n)               for(int i=0;i<n;i++)
#define aint(a)                  a.begin(), a.end()
#define pb                      push_back
#define endl                    "\n"
#define ff                      first
#define ss                      second
#define asort(c)                sort(aint(c)) 
#define lbpos(x,v)              (int)(lower_bound(aint(v),x)-v.begin())//=v.size()==>No LB 
#define ubpos(x,v)              (int)(upper_bound(aint(v),x)-v.begin())//=v.size()==>No UB
#define PI                      3.14159265358979323846
#define int                     long long
typedef  vector<int>                 vi;
typedef  pair<int, int>              ii;
typedef  vector<ii>                 vii;
typedef  long double                 ld;
#define debug(...) ZZ(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1> void ZZ(const char* name, Arg1&& arg1){std::cerr << name << " = " << arg1 << endl;}
template <typename Arg1, typename... Args>void ZZ(const char* names, Arg1&& arg1, Args&&... args)
{
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
clock_t time_p=clock();
void timer()
{
    time_p=clock()-time_p;
    cerr<<"Execution Time: "<<(double)(time_p)/CLOCKS_PER_SEC<<"\n";
}


int32_t main()
{
  FIO;
  int n,p;
  cin>>n>>p;
  if(n==1)
  {
    cout<<p; return 0;
  }
  if(p<=n)
  {
    cout<<1; return 0;
  }
  int init=ceil(pow(p, 1.0/n));
 // debug(init);
  init=max(2LL,init+2);
  int ans=1LL;
  rep(i,2,init)
  {
    int cnt=0;
    int num=p;
    while(num%i==0)
    {
      num/=i;
      cnt++;
    }
    if(cnt>=n)
      ans=max(ans,i);
  }
  cout<<ans;
  timer();
  return 0;
}  