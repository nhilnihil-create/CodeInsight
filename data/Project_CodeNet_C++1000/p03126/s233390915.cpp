#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long int ll;

int main() {
  
  int n, m;
  cin >> n >> m;
  
  int c[m] = {0};
  int k, a;
  REP(i,n) {
    cin >> k;
    REP(j,k) {
      cin >> a;
      c[a-1]++;
    }
  }
  
  int ans = 0;
  REP(i,m) {
    if (c[i] == n) ans++;
  }
  
  cout << ans << endl;    
  
}
