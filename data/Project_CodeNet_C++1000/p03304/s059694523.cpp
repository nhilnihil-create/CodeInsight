#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0; i < (n); ++i)
#define REPR(i,n) for(int i=(n); i >= 0; --i)
#define FOR(i, m, n) for(int i = (m); i < (n); ++i)

using ll = long long;
#define INF 1e9

int n, m, d;

int main(){
  cin >> n >> m >> d;
  if(n<1){
    cout << 0 << endl;
  }
  ll c = n-d;
  cerr << "c:" << c << endl;
  double ans = (double)c*(m-1)*2/((double)n*n);
  if(d == 0){
    ans /= 2;
  }
  printf("%.10f\n", ans);
  return 0;
}
