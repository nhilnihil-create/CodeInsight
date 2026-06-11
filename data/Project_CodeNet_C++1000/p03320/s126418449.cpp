//Be Name Khoda
/*
tane adami sharifast be jane adamiat
na hamin lebase zibast neshane adamiat
agar adami be cheshmasto dahano goosho bini
che miane naghshe divaro miane adamiat
khoro khabo khashmo shahvat shaghab asto jahlo zolmat
hayavan khabar nadarad ze jahane adamiat
be haghighat adami bash vagarna morgh bashad
ke hami sokhan begooyad be zabane adamiat
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T> using ordered_set =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset =  tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
typedef long long LL;
typedef LL ll;
typedef long double ld;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;
 
 
#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (ll i=a;i<b;++i)
#define Ford(i,a,b) for (ll i=a;i>=b;--i)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))
#define RET(x) { cout << x; exit(0); }
#define MKP make_pair
#define RETD(x) { cout << fixed << setprecision(15) << x; } //exit(0); }
#define GEI(x) scanf("%d",&x)
#define GEL(x) scanf("%lld",&x)
#define ALL(x) x.begin(),x.end()
const ll M=1e5+5,LG=20,SM=1000,inf=1e9+5;
ll mod=1e9+7;
ll pw(ll a,ll n) { return (n==0?1:pw(a*a%mod,n/2)*(n%2?a:1)%mod); }
#define MOK(x) if (x>mod) x-=mod;

ll s(ll x){
  if (x<10) return x;
  return s(x/10)+x%10;
}

vll v,v2;

int main(){
  ios::sync_with_stdio(0);
  ll k;
  cin >> k;
  For(i,1,1000){
    ll x=i;
    For(j,0,15){
      v.PB(x);
      x*=10;
      x+=9;
    }
  }
  sort(ALL(v));
  v.resize(unique(ALL(v))-v.begin());
  ld bst=1e20;
  reverse(ALL(v));
  for(ll x:v){
    if (bst<(ld)x/(ld)s(x)) continue;
    bst=(ld)x/(ld)s(x);
    v2.PB(x);
  }
  reverse(ALL(v2));
  For(i,0,k) cout << v2[i] << '\n';
}

