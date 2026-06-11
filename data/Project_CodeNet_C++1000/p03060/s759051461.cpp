#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int n;
  cin >> n;
  
  int v[n], c[n];
  REP(i,n) cin >> v[i];
  REP(i,n) cin >> c[i];
  
  int all = 1 << n;
  int m = 0;
  REP(k,all) {
    int x = 0, y = 0;
    REP(i,n) {
      if ((k >> i) & 1) {
        x += v[i], y += c[i];
      }
    }
    m = max(m, x-y);
  }
  
  cout << m << endl;
  
}