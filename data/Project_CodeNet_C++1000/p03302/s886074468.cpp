#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define RFOR(i,a,b) for(int i=(int)(b)-1;i>=(int)(a);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define LL long long
#define INF INT_MAX

const double EPS = 1e-14;
const double PI  = acos(-1.0);


int main(){
  int a, b;
  cin >> a >> b;

  string ans;
  if (a + b == 15) ans = "+";
  else if (a * b == 15) ans = "*";
  else ans = "x";

  cout << ans << endl;
}
