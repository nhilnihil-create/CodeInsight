#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int d, n;
  cin >> d >> n;
  
  if(d==0) {
    if(n!=100) {
    cout << n << endl;
    return 0;
    }
    else {
    cout << 101 << endl;
    return 0;
    }
  }
  else {
    int x, ans;
    int count = 0;
    for(int i=100; ; i+=100) {
      x = i;
      for(int j=1; j<=d; j++) {
        if(x%100 != 0) break;
        x /= 100;
        if(j==d && x%100 != 0) count++; 
      }
      if(count==n) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
    return 0;
  }
}