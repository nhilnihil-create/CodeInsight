#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);



int main(){
  int n = 5;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  int ans = 0;
  int MX = 0;

  REP(i,n){
    if(a[i]%10 == 0) ans += a[i];
    else{
      ans += a[i]/10 * 10 + 10;
      MX = max(MX, 10 - a[i]%10);
    }
  }

  cout << ans - MX << endl;
  return 0;
}