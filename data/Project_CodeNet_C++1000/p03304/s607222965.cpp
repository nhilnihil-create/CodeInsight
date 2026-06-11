#include <bits/stdc++.h>
using namespace std;

int main(){
  long double d, n, m;
  cin >> n >> m >> d;
  
  long double ans;
  if(d == 0) ans = 1 / n * (m-1);
  else ans = 2 * (n-d) / n / n * (m-1);
  
  cout << setprecision(10) << ans << endl;
}