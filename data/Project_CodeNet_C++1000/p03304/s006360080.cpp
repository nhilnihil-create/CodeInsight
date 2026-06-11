#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t n, m, d; 
  cin >> n >> m >> d;

  double ans = (double)max((int64_t)0, n-d) * (m-1) / (n*n);
  if(d != 0) ans *= 2;
  cout << setprecision(10);
  cout << ans << endl;

  
}


  
  