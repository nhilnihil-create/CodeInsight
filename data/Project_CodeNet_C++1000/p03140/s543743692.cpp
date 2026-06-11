#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (int)x.size()
#define SP(x)  setprecision((int)x)


using namespace std ;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数


int main()
{
  int n ;
  cin >> n ;
  string a, b, c;
  cin >> a >> b >> c ;
  int ans = 0 ;
  
  REP(i,n){
    int cnt = 0 ;
    if(a.at(i)!=b.at(i)){
      cnt++ ;
    }
    if(b.at(i)!=c.at(i)){
      cnt++ ;
    }
    if(c.at(i)!=a.at(i)){
      cnt++ ;
    }
    if(cnt==3){
      ans += 2 ;
    }
    else if(cnt==2){
      ans += 1 ;
    }
  }
  
  cout << ans <<endl ;
    
    


  return 0 ;
}

