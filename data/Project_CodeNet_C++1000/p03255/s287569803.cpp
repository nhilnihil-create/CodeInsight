#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pcnt __builtin_popcount
#define sz(x) (int)(x).size()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define show(x) cout<<#x<<" = "<<x<<endl;
#define rng(a) (a.begin()),(a.end())
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
typedef long long ll;
typedef __int128_t lll;
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;
template<typename T>string join(V<T>&v){stringstream s;FOR(i,0,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename A,size_t N,typename T>void Fill(A (&array)[N],const T&v){fill((T*)array,(T*)(array+N),v);}
lll gcd(lll a,lll b,lll &x,lll &y){if(!b){x=1;y=0;return a;}lll d=gcd(b,a%b,y,x);y-=a/b*x;return d;}
ll gcd(ll a,ll b){lll x=0,y=0;return gcd(a,b,x,y);}
ll modpow(lll a,lll n,ll m){if(!a)return a;lll p=1;for(;n>0;n>>=1,a=a*a%m)if(n&1)p=p*a%m;return(ll)p;}
bool isprime(ll n){if(n<2)return 0;if(!(n%2))return !(n-2);lll d=n-1,t,y;while(!(d%2))d>>=1;V<ll> al={2,325,9375,28178,450775,9780504,1795265022};for(ll a:al){if(n<=a)break;t=d,y=modpow(a,t,n);while(t!=n-1&&y!=1&&y!=n-1)y=y*y%n,t<<=1;if(y!=n-1&&!(t%2))return 0;}return 1;}
void dout(double d){printf("%.12f\n",d);}
void YN(bool z){cout<<(z?"YES\n":"NO\n");}
void Yn(bool z){cout<<(z?"Yes\n":"No\n");}
void yn(bool z){cout<<(z?"yes\n":"no\n");}
mt19937 rnd; void set_rnd(){random_device r;rnd=mt19937(r());}
V<ll> fact, rfact; void set_fact(int n, ll m){fact.pb(1);rfact.pb(1);FOR(i,1,n+1)fact.pb(fact[i-1]*i%m),rfact.pb(modpow(fact[i],m,m-2));}
const int iinf = 1e9+6;
const ll linf = 1e18;
const int mod = 1e9+7;
const double pi = acos(-1);
const double eps = 1e-10;
const int N = 2e5+1;
void init(){
  set_rnd();
//  set_fact(N);
}
int n;
ll t, X;
lll x[N];

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  init();
  cin >> n >> X;
  FOR(i, 1, n+1) cin >> t, x[i]=t;
  reverse(x+1, x+n+1);
  FOR(i, 0, n) x[i+1] += x[i];
  lll ans = lll(linf)*linf;
  FOR(i, 1, n+1){
    int l=0, r=i, c=3;
    lll _ans = (x[r]-x[l])*2 + X*(i+n);
    while(true){
      mins(r, n);
      _ans += (x[r]-x[l]) * c;
      if(r==n) break;
      l += i;
      r += i;
      c += 2;
    }
    mins(ans, _ans);
  }
  cout << ll(ans) << endl;
  return 0;
}