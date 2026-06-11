#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int MOD = 1e9 + 7;

signed main(){

  int n, m, d; cin >> n >> m >> d;
  if(d == 0){
    printf("%.7f\n", 1.0 * (m - 1) / n);
  }else{
    printf("%.7f\n", 1.0 * (m - 1) * 2 * (n - d) / (n * n));
  }

  return 0;
}
