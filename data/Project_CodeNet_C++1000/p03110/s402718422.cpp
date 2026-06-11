#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n;
  cin >> n;
  double ans = 0;
  REP(i,n){
    double x;
    string u;
    cin >> x >> u;
    if(u == "JPY") ans += x;
    if(u == "BTC") ans += x * 380000;
  }

  cout << ans << endl;
  return 0;
}
