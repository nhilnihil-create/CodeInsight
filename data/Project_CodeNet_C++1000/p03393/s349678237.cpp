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
  str s ;
  cin >> s ;
  vstr st ;
  int n = SZ(s) ;
  vint cnt(26,0);
  if(s=="zyxwvutsrqponmlkjihgfedcba"){
    cout << -1 <<endl ;
    return 0 ;
  }
  REP(i,n){
    cnt[s[i]-'a']++ ;
  }
  if(n<=25){
    cout << s ;
    REP(i,26){
      if(cnt[i]==0){
        cout << (char)(i+'a') <<endl ;
        return 0 ;
      }
    }
  }
  else{
    set<char> S ;
    for(int i=n-1;i>=1;i--){
      str hoge = s ;
      S.insert(s[i]) ;
      auto itr = S.begin() ;
      hoge = s.substr(0,i-1) + (*itr) ;
      if(s<hoge){
        set<char> T ;
        REP(j,SZ(hoge)){
          T.insert(hoge[j]) ;
        }
        if(SZ(T)==SZ(hoge)){
          st.PB(hoge) ;
        }
      }
      hoge = s.substr(0,i-1) ;
      REP(j,26){
        hoge[SZ(hoge)-1] =  (char)(hoge[SZ(hoge)-1]+1) ;
        if(hoge[SZ(hoge)-1]-'a'<0 ||hoge[SZ(hoge)-1]-'a'>=26){
        continue ; ;
        }
        if(s<hoge){
          set<char> T ;
          REP(j,SZ(hoge)){
            T.insert(hoge[j]) ;
          }
          if(SZ(T)==SZ(hoge)){
            st.PB(hoge) ;
          }
        }
      }
    }
  }
  sort(ALL(st)) ;
  cout << st[0] <<endl ;
        
   
  return 0 ;
}