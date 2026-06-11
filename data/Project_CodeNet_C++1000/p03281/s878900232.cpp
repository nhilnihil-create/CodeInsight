#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int count = 0;
  int ans = 0;
  for(int i=1; i<=n; i=i+2) {
    for(int j=1; j<=i; j++) {
      if(i%j==0) count++;
      if(j==i) {
        if(count==8) ans++;
        count = 0;
      }
    }
  }
  cout << ans << endl;
}