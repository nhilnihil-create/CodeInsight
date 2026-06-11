#include <bits/stdc++.h>
using namespace std;
// type alias
typedef long long LL;
typedef pair<int,int> II;
typedef tuple<int,int,int> III;
typedef vector<int> VI;
typedef vector<string> VS;
typedef unordered_map<int,int> MAPII;
typedef unordered_set<int> SETI;
template<class T> using VV=vector<vector<T>>;
// minmax
template<class T> inline T SMIN(T& a, const T b) { return a=(a>b)?b:a; }
template<class T> inline T SMAX(T& a, const T b) { return a=(a<b)?b:a; }
// repetition
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n)  for(int i=0;i<=(n);++i)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  for(int i=0;i<(n);++i)
#define FORR(x,arr) for(auto& x:arr)
#define SZ(a) int((a).size())
// collection
#define ALL(c) (c).begin(),(c).end()
// DP
#define MINUS(dp) memset(dp, -1, sizeof(dp))
#define ZERO(dp) memset(dp, 0, sizeof(dp))
// stdout
#define println(args...) fprintf(stdout, ##args),putchar('\n');
// debug cerr
template<class Iter> void __kumaerrc(Iter begin, Iter end) { for(; begin!=end; ++begin) { cerr<<*begin<<','; } cerr<<endl; }
void __kumaerr(istream_iterator<string> it) { (void)it; cerr<<endl; }
template<typename T, typename... Args> void __kumaerr(istream_iterator<string> it, T a, Args... args) { cerr<<*it<<"="<<a<<", ",__kumaerr(++it, args...); }
template<typename S, typename T> std::ostream& operator<<(std::ostream& _os, const std::pair<S,T>& _p) { return _os<<"{"<<_p.first<<','<<_p.second<<"}"; }
//#define __KUMATRACE__ true
#ifdef __KUMATRACE__
#define dump(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); __kumaerr(_it, args); }
#define dumpc(ar) { cerr<<#ar<<": "; FORR(x,(ar)) { cerr << x << ','; } cerr << endl; }
#define dumpC(beg,end) { cerr<<"~"<<#end<<": "; __kumaerrc(beg,end); }
#else
#define dump(args...)
#define dumpc(ar)
#define dumpC(beg,end)
#endif

// $ cp-batch Test | diff Test.out -
// $ g++ -std=c++14 -Wall -O2 -D_GLIBCXX_DEBUG -fsanitize=address Test.cpp && ./a.out

/*

 5/18/2020

 9:28-10:00 give up

 */

string S,T;
int N,si,sj,H,W;

map<char,int> ms={{'R',0},{'D',1},{'L',2},{'U',3}};
vector<pair<int,int>> moves = { {0,1}/*R*/,{1,0}/*D*/,{0,-1}/*L*/,{-1,0}/*U*/ };
II move(string &s, int i) {
  return moves[ms[s[i]]];
}

bool f(string S, string T, int p) {
  dump(p,W);
  dump(S);
  dump(T);
  int cntrT=0;
  REP(i,N) {
    if(S[i]=='R') cntrT++;
  }
  REP(i,N) {
    if(S[i]=='L') --p;
    if(S[i]=='R') cntrT--;
    if(p<=0||p>W) return false;
    if(T[i]=='R'&&p<W) ++p;
    p=min(p,N-cntrT);
    dump(i,p);
    if(p<=0||p>W) return false;
  }
  return true;
}

void swap(string &s, string &t, char x, char y) {
  REP(i,N) {
    if(S[i]==x) S[i]=y;
    else if(S[i]==y) S[i]=x;
    if(T[i]==x) T[i]=y;
    else if(T[i]==y) T[i]=x;
  }
}

bool solve() {
  VI res;
  res.push_back(f(S,T,sj));
  swap(S,T,'L','R');
  res.push_back(f(S,T,W-sj+1));
  swap(S,T,'L','R');
  swap(S,T,'L','U');
  swap(S,T,'R','D');
  swap(H,W);
  res.push_back(f(S,T,si));
  swap(S,T,'L','R');
  res.push_back(f(S,T,W-si+1));
  dumpc(res);
  bool fall=count(ALL(res),0);
  return !fall;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout<<setprecision(12)<<fixed;

  cin>>H>>W>>N>>si>>sj>>S>>T;
  cout<<(solve()?"YES":"NO")<<endl;

  return 0;
}
