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
typedef vector<VC> VVC;
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

LL Gcd(LL a, LL b) {
  if (a < b) {
    return Gcd(b,a);
  }
  if (b == 0) {
    return a;
  }
  else {
    return Gcd(b,a%b);
  }
}

LL Lcm(LL a, LL b) {
  LL abd = Gcd(a,b);
  LL x = a / abd, y = b / abd;
  
  return x*y*abd;
}


LL RepSqu(LL N, LL P, LL M) {
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
  
  int N;
  cin >> N;
  N++;
  VI A(N,0);
  
  REP(i,N-1){
    cin >> A.at(i+1);
  }
  
  SORT(A);
  
  REP(i,N){
    if(i%2){
      continue;
    }
    A.at(i) = 24 - A.at(i);
  }
  
  SORT(A);
  
  int del =A.at(N-1) - A.at(0);
  chmin(del,24-del);
  
  REP(i,N-1){
    chmin(del, A.at(i+1)-A.at(i));
  }
  
  cout << del << endl;
  
  return 0;
}