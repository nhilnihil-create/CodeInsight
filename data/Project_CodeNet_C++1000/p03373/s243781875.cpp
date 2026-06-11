#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()
#define SUM(a)  accumulate((a).begin(),(a).end(),0)
#define SORT(a) sort(ALL(a))
#define REV(a) reverse(ALL(a))
#define dump(x)  cerr << #x << " = " << (x) << endl;
typedef long long ll;
const int INF = 999999999;
const int MOD = (int)1e9 + 7;
const int EPS = 1e-9;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a,b,c,x,y;
  cin >> a >> b >> c >> x >> y;
  int ans = 0;
  if (2*c<=(x>y?a:b)){
      ans = 2*c*max(x,y);
  }else if (a+b>2*c){
      int mn = min(x,y);
      x -= mn;
      y -= mn;
      ans = mn*2*c + x*a + y*b;
  }else{
      ans = x*a+y*b;
  }
  cout << ans << endl;



}