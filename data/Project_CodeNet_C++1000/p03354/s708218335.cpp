#include <bits/stdc++.h>
using namespace std;
#define popcnt(a) __builtin_popcount(a)
#define FastIO() ios::sync_with_stdio(false), cin.tie(0);
#define IO() freopen("palindrome.in","rw",stdin)
#define error(args...)                       \
{                                            \
    cerr<<"LINE "<<__LINE__;                 \
    string _s = #args;                       \
    replace(_s.begin(), _s.end(), ',', ' '); \
    stringstream _ss(_s);                    \
    istream_iterator<string> _it(_ss);       \
    err(_it, args);                          \
    cerr<<endl;                              \
}
void err(istream_iterator<string> it)
{
} 
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
  cerr<<' '<< *it << " = " << a ;
  err(++it, args...);
} 
typedef long long ll;
const int N = 1e6+9, M = 1e2+9, OO = 0x3f3f3f3f,MOD = 1e9 + 7;
int par[N],sz[N],arr[N],n;
void init()
{
  iota(par+1,par+n+1,1);
  fill(sz,sz+n+1,1);
}
int find(int p)
{
  return p==par[p] ? p : par[p]=find(par[p]);
}
void join(int a,int b)
{
  a = find(a);
  b = find(b);
  if(a==b) return;
  if(sz[a]<sz[b]) swap(a,b);
  par[b] =a;
  sz[a] += sz[b];

}
int main()
{
  
  int m,ans=0;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i) scanf("%d",arr+i);
  init();
  while(m--)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    join(par[x],par[y]);
  }
  for(int i=1;i<=n;++i) ans += (find(i)==find(arr[i]));
  
  printf("%d\n",ans);
  #ifdef _LOCAL_DEFINE  
  cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
  #endif
  return 0; 
}

