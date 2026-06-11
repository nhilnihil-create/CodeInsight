#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int ans = 0;
  if (n == 1) ans = 1;
  else{ 
    REP(i,n) {
      int j = 2;
      while(1) {
        if (pow(i+2,j) <= n) ans = max(ans,int(pow(i+2,j)));
        else break;
        j++;
      }
    }
  }
  
  cout << ans << endl;
  
}
