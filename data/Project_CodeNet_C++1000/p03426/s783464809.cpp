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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL,LL> PLL;
typedef map<int,int> MII;
typedef queue<int> QI;
typedef queue<PII> QPII;
typedef stack<int> SI;
typedef stack<PII> SPII;
typedef deque<int> DI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef vector<PII> VPII;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define PF push_front
#define POB pop_back()
#define POF pop_front()
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define LB lower_bound
#define UB upper_bound
#define SORTR(c) sort((c).begin(), (c).end(), greater<int>())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define FORR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REPR(i,n) RFOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);
const LL INF = INT_MAX;
const LL LINF = LLONG_MAX;
const LL MOD = 1e9+7;
const LL MODD = 998244353;

//other
//-------------------------------------------
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define FI first
#define SE second

//memo
// << fixed << setprecision()

VI dx = {1,0,-1,0,1,1,-1,-1};
VI dy = {0,1,0,-1,1,-1,1,-1};

LL Gcd(LL a, LL b) {
  return __gcd(a,b);
}

LL Lcm(LL a, LL b) {
  LL abd = Gcd(a,b);
  LL x = a / abd, y = b / abd;
  
  return x*y*abd;
}


LL RepSqu(LL N, LL P, LL M) {
  if(N == 0) {
    return 0;
  }
  
  if(P == 0) {
    return 1;
  }
  if(P%2 == 0) {
    LL t = RepSqu(N, P/2, M);
    return t*t % M;
  }
  return (N * RepSqu(N, P-1, M)) % M;
}


int main() {
  
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int H,W,D,E,A,L,R;
  cin >> H >> W >> D;
  VPII xy(H*W);
  VI DP(H*W,0);
  REP(i,H){
    REP(j,W){
      cin >> A;
      xy.at(A-1) = MP(i,j);
    }
  }
  
  FOR(i,D,H*W){
    DP.at(i) = DP.at(i-D) + abs(xy.at(i).FI - xy.at(i-D).FI) + abs(xy.at(i).SE - xy.at(i-D).SE);
  }
  
  int Q;
  cin >> Q;
  
  REP(i,Q){
    cin >> L >> R;
    L--,R--;
    cout << DP.at(R) - DP.at(L) << endl;
  }
                                                                
  return 0;
}