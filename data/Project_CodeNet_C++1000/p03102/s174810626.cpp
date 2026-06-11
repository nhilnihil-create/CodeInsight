#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n, m, c;
  cin >> n >> m >> c;
  
  vector<int> b(m);
  REP(i,m) cin >> b[i];
  
  int a, sum, ans = 0;
  REP(i,n) {
    sum = 0;
    REP(j,m) {
      cin >> a;
      sum += a * b[j];
    }
    sum += c;
    if (sum > 0) ans++;
  }
  
  cout << ans << endl;
  
}     