#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  double n, t, a;
  cin >> n >> t >> a;
  
  double m = 10000;
  int ans = 0;
  REP(i,n) { 
    double h;
    cin >> h;
    double c = abs(a-(t-h*0.006));
    m = min(m,c);
    if (m == c) ans = i+1;    
  }
 
  cout << ans << endl;
  
}