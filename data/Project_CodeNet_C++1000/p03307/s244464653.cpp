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

  int ans = n/__gcd(2,n)*2;
  cout << ans << endl;

  return 0;
}
