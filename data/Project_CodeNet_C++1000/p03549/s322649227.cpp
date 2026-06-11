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

//xのy乗をpで割った余り

ll pow(ll x,ll y,ll m){
    ll res = 1 ;
    if(y>0){
        res = pow(x,y/2,m) ;
        if(y%2==0){
            res = (res*res)%m ;
        }
        else{
            res = (((res*res)%m)*x)%m ;
        }
    }
    return res ;
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
  int n, m ;
  cin >> n >> m ;
  int ans = 0 ;
  int time = 1900*m+100*(n-m) ;
  int per = pow(2,m,MOD) ;
  cout << time*per <<endl ;
  
  
  
  
  return 0 ;
}


