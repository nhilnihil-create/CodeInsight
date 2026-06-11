#include <bits/stdc++.h>
#define FOR(v, a, b) for(int v = (a); v < (b); ++v)
#define FORE(v, a, b) for(int v = (a); v <= (b); ++v)
#define REP(v, n) FOR(v, 0, n)
#define REPE(v, n) FORE(v, 0, n)
#define REV(v, a, b) for(int v = (a); v >= (b); --v)
#define ALL(x) (x).begin(), (x).end()
#define ITR(it, c) for(auto it = (c).begin(); it != (c).end(); ++it)
#define LLI long long int
using namespace std;
template <typename T> using V = vector<T>;
template <typename T, typename U> using P = pair<T,U>;
template <typename I> void join(ostream &ost, I s, I t, string d=" "){for(auto i=s; i!=t; ++i){if(i!=s)ost<<d; ost<<*i;}ost<<endl;}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  LLI n,a,b; cin >> n >> a >> b;

  vector<int> ans(n);

  if(a+b > n+1 || a*b < n){
    cout << -1 << endl;
    return 0;
  }

  REP(i,a) ans[i] = n-a+i+1;

  int k = 0;
  for(int i=a; i<n;){
    if(n-i >= b-1){
      REP(j,b-1){
	ans[i+j] = k+b-1-j;
      }
      k += b-1;
      i += b-1;
    }else{
      int t = n-i;
      REP(j,t){
	ans[i+j] = k+t-j;
      }
      break;
    }
  }
  
  join(cout, ALL(ans));
  
  return 0;
}
