#include <bits/stdc++.h>
using namespace std;
#ifdef _DEBUG
  #include "_DEBUG.hpp"
#endif
#define int long long
const int INF = 1LL << 60;

signed main(){

  int n; cin >> n;
  vector<int> c(n), s(n), f(n);
  for(int i = 0; i < n-1; i++){
    cin >> c[i] >> s[i] >> f[i];
  }

  for(int i = 0; i < n; i++){
    int pos = i, t = 0;
    while(pos != n-1){
      if(t > s[pos]){
        //mul = (t - s[pos]) / f[pos];
        int left = -1, right = 1e10;
        while(right - left > 1){
          int mid = (left + right) / 2;
          (t <= s[pos] + f[pos] * mid ? right : left) = mid;
        }
        t = s[pos] + f[pos] * right + c[pos];
      }else{
        t = s[pos] + c[pos];
      }
      pos++;
      //cout << i << " -> " << pos << " " << t << endl;
    }
    cout << t << endl;
  }

  return 0;
}