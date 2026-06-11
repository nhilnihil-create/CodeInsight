#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);

  int ans = 0;
  int sum = 0;
  REP(i,m) cin >> b[i];

  REP(i,n){
    sum = c;
    REP(j,m){
      int a;
      cin >> a;
      sum += a*b[j];
    }
    if(sum > 0){
      ++ans;
    }
  }

  cout << ans << endl;
  return 0;
}