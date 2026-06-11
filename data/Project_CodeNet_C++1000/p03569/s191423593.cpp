#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef pair<ll,ll> pll ;
typedef vector<pii> vpii ;
typedef vector<pll> vpll ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define CHI 1000000000000000003
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define NP next_permutation
#define SZ(x)  (ll)x.size()
#define SP(x)  setprecision((ll)x)

const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
const double PI = M_PI;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}
//-----------------------------------------




















//-----------------------------------------
int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  str s ;
  cin >> s ;
  int n = SZ(s) ;
  str t = "" ;
  REP(i,n){
    if(s[i]!='x'){
      t += s[i] ;
    }
  }
  str u = t ;
  reverse(ALL(u)) ;
  
  if(u!=t){
    cout << -1 <<endl ;
    return 0 ;
  }
  else{
    int ans = 0 ;
    int m = SZ(u) ;
    vector<int> sp(m+1) ;
    int i=0;
    int j=0;
    while(i<n){
      if(s[i]=='x'){
        sp[j]++ ;
      }
      else{
        j++ ;
      }
      i++ ;
    }
    vector<int> sp2 ;
    sp2 = sp ;
    reverse(ALL(sp2)) ;
    REP(i,m+1){
      ans += abs(sp2[i]-sp[i]) ;
    }
    cout << ans/2 <<endl; 
  }
  
  
  
  
  return 0 ;
}

