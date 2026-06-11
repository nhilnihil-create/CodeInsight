#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> p(n), a(n);
  for(int i = 0; i < n; i++){
    cin >> p[i];
    a[p[i]-1] = i;
  }

  int res = 1, cnt = 1; //操作しない数
  for(int i = 1; i < n; i++){
    if(a[i-1] < a[i]){
      res++;
    }else {
      res = 1;
    }
    cnt = max(res, cnt);
  }
  cout << n - cnt << endl;

  return 0;
}
