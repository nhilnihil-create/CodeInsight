#include<bits/stdc++.h>
#define rep(i,m) for(long long i=0; i<m; i++)
#define per(i,m) for(long long i=m-1; i>=0; i--)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define ROF(i,n,m) for(long long i=n-1; i>=m; i--)
#define all(x) (x).begin(),(x).end()
#define EPS (1e-7)
#define INF (1e18)
#define PI (acos(-1))
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
typedef pair<ll, ll> LP;
 
ll POW(ll m,ll n)
{
  if(n<0) return 0;
  if(n==0) return 1;
  return m*POW(m,n-1)%MOD;
}
 
ll gcd(ll u, ll v) {
  ll r;
  while (0 != v) {
    r = u % v; u = v; v = r;
  }
  return u;
}
 
ll KAI(ll m)
{
  if(m<0) return 0;
  if(m==0) return 1;
  return m*KAI(m-1)%MOD;
}
 
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x);
    y -= a / b * x;
    return d;
}
 
inline ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
 
ll modinv(ll a, ll m) {
    ll x, y;
    extGCD(a, m, x, y);
    return mod(x, m);
}
 
ll COM(ll m,ll n)
{
  if(m<n) return 0;
  if(n<0) return 0;
  if(n==0) return 1;
  if(m==n) return 1;
  return m%MOD*COM(m-1,n)%MOD*modinv(m-n,MOD)%MOD;
}
 

int main()
{
  ll n,k,v[1100][1100],c;
  cin >> n;
  k=0;
  FOR(i,2,1100)if(i*(i-1)==2*n)k=i;
  if(k==0)printf("No");
  else
  {c=1;
   rep(i,k-1){
     FOR(j,i+1,k){
       v[i][j-1]=c;
       v[j][i]=c;
       c++;
     }
   }
   printf("Yes\n");
   printf("%lld\n",k);
   rep(i,k){
     printf("%lld",k-1);
     rep(j,k-1){printf(" %lld",v[i][j]);
             }
     printf("\n");
   }
  }
}