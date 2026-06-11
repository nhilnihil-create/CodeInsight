// Charan Sriramula

#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long int ll;

const ll logx=30;
const ll N=1e6+5;
const ll INF=1e18+5;
const ll mod=1e9+7;
const double PI = 3.14159265358979323846;

#define ints(n) scanf("%d",&n)
#define intp(n) printf("%d\n",n)
#define longs(n) scanf("%intd",&n)
#define longp(n) printf("%intd\n",n)

inline ll mul(ll a, ll b, ll p){ return (a * 1ll * b) % p; }
inline ll sub(ll a, ll b, ll p){ ll c = a - b; if(c < 0) c += p; return c; }
inline ll add(ll a, ll b, ll p){ ll c = a + b; if(c > p) c -= p; return c; }

#define f first
#define s second
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define mp(x,y) make_pair(x,y)
#define GCD(a,b) __gcd((a),(b))
#define all(v) v.begin(),v.end()
#define bits(x) __builtin_popcount(x)
#define LCM(a,b) ((a)*(b))/GCD((a),(b))
#define ms(dp,val) memset(dp,val,sizeof(dp))
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
template<typename T> T power(T x,T y,ll m){T ans=1;while(y>0){if(y&1LL) ans=(ans*x)%m;y>>=1ll;x=(x*x)%m;}return ans%m;}

#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl

ll n,a[N],dp1[(1<<19)][20],dp2[(1<<19)][20];

ll F(ll mask,ll idx)
{
  ll res=-1;
  if(idx==-1){return a[mask];}
  if(dp1[mask][idx]!=-1){return dp1[mask][idx];}
  if(mask&(1<<idx))
  {
    res=max(res,F(mask,idx-1));
    res=max(res,F(mask^(1<<idx),idx-1));
  }
  else{res=max(res,F(mask,idx-1));}
  return dp1[mask][idx]=res;
}

ll Q(ll mask,ll idx)
{
  ll res=-1;
  ll set=mask&(1<<idx);
  ll val=mask&((1<<idx)-1);
  if(val==0&&set)
  {
    ll maxi=-1;
    maxi=max(maxi,dp1[mask][idx-1]+dp1[mask^(1<<idx)][idx-1]);
    return maxi;
  }
  if(idx==-1){return 0;}
  if(dp2[mask][idx]!=-1){return dp2[mask][idx];}
  if(mask&(1<<idx))
  {
    res=max(res,Q(mask,idx-1));
    res=max(res,Q(mask^(1<<idx),idx-1));
    res=max(res,dp1[mask][idx-1]+dp1[mask^(1<<idx)][idx-1]);
  }
  else
  {
    res=max(res,Q(mask,idx-1));
  }
  return dp2[mask][idx]=res;
}

int main()
{
  fast;
  cin>>n;
  ms(dp1,-1);
  ms(dp2,-1);
  ll maxi=-1;
  for(ll i=0;i<(1<<n);i++){cin>>a[i];}
  for(ll mask=0;mask<(1<<19);mask++){dp1[mask][19]=F(mask,19);dp1[mask][-1]=a[mask];}
  for(ll mask=0;mask<(1<<19);mask++){dp2[mask][19]=Q(mask,19);}
  for(ll mask=1;mask<(1<<n);mask++)
  {
    maxi=max(maxi,dp2[mask][19]);
    cout<<maxi<<endl;
    //cout<<mask<<" "<<dp2[mask][19]<<endl;
  }
}