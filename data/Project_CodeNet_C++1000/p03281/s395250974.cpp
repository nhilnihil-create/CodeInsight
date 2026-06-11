#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int ans = 0;
  if (n < 105) ans = 0;
  else {
    for (int i = 105; i < n+1; i+=2) {
      int c = 0;
      REP(j,i) {
        if (i % (j+1) == 0) c++;
      }
      if (c == 8) ans++;
    }
  }
  
  cout << ans << endl;

}
