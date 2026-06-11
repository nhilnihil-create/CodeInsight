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
ll prexor[N],csum[N];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i=1;i<=n;++i)
  {
    int x;
    scanf("%d",&x);
    prexor[i]=prexor[i-1]^x;
    csum[i]=csum[i-1]+x;
  }
  int r=1;
  ll ans=0;
  for(int l=1;l<=n;++l)
  {
    
    while(r<=n && (csum[r]-csum[l-1] == (prexor[r]^prexor[l-1]))) r++;
    ans+=(r-l);
  }
  printf("%lld\n",ans);
  #ifdef _LOCAL_DEFINE  
  cerr << (double)clock() * 1.0 / CLOCKS_PER_SEC << endl;
  #endif
  return 0; 
}

