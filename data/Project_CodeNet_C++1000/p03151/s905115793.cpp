#include <bits/stdc++.h>

using namespace std ;
typedef long long ll;
typedef string str;
typedef vector<int> vint;
typedef vector<double> vdou ;
typedef vector<ll> vll;
typedef vector<vint> vvint;
typedef vector<str> vstr;
typedef pair<int, int> pii;
typedef vector<pii> vpii ;

#define REP(i, n) for (ll (i) = 0; (i) < (ll)(n); i++) 
#define FOR(i, a, b) for(ll (i) = a; (i) < (ll)b; i++)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
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

//-------------------------------------------------
// 
void yes(){
  cout <<"Yes"<<endl ;
}
void no(){
  cout <<"No"<<endl ;
}


//-------------------------------------------------
// メモ
/*






*/
//-------------------------------------------------


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n ;
  cin >> n ;
  vll a(n) ;
  vll b(n) ;
  vll dif(n) ;
  ll suma = 0 ;
  ll sumb = 0 ;
  ll cnts = 0 ;
  ll answ = 0 ; 
  REP(i,n){
    cin >> a[i] ;
    suma += a[i] ;
  }
  REP(i,n){
    cin >> b[i] ;
    sumb += b[i] ;
    dif[i] = a[i] -b[i] ;
  }
  
  if(suma<sumb){
    cout << -1 <<endl;
    return 0 ;
  }
  sort(ALL(dif)) ;
  reverse(ALL(dif)) ;
  
  vll ruiseki(n,0) ;
  ruiseki[0] = dif[0] ;
  if(dif[n-1]>=0){
    cout << 0 <<endl ;
    return 0 ;
  }
  REP(i,n-1){
    ruiseki[i+1] = ruiseki[i] + dif[i+1] ;
  }
  REP(i,n){
    if(a[i]<b[i]){
      cnts += b[i] - a[i] ;
      answ++ ;
    }
  }
  REP(i,n){
    if(ruiseki[i]<cnts){
      answ++ ;
    }
    else{
      break ;
    }
  }
  
  
  
  cout << answ+1 <<endl ;
      
    
  
  
  
  return 0 ;
}

