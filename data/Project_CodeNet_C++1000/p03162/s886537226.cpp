#include <bits/stdc++.h>
using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<char> VC;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define LB lower_bound
#define UB upper_bound

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL INF = 1e9;
const LL MOD = 1e9+7;

//other
//-------------------------------------------
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define FI first
#define SE second

//memo
// setprecision()

int main() {
  int N;
  cin >> N;
  VI a(N),b(N),c(N);
  
  REP(i,N){
    cin >> a.at(i) >> b.at(i) >> c.at(i) ;
  }
  
  VI Dpa(N+1),Dpb(N+1),Dpc(N+1);
  
  REP(i, N){
    Dpa.at(i+1) = a.at(i) + max(Dpb.at(i),Dpc.at(i));
    Dpb.at(i+1) = b.at(i) + max(Dpc.at(i),Dpa.at(i));
    Dpc.at(i+1) = c.at(i) + max(Dpa.at(i),Dpb.at(i));
  }
  
  cout << max({ Dpa.at(N), Dpb.at(N), Dpc.at(N)}) << endl;
  
  return 0;
}
