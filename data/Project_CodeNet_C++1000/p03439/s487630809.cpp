#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main(){
  int n;
  cin >> n;
  int l, r;
  l = 0; r = n;
  string sl, sr, sm;
  cout << 0 << endl;
  fflush(stdout);
  cin >> sl;
  if(sl == "Vacant") return 0;
  sr = sl;
  while(true) {
    int m = (l+r)/2;
    cout << m << endl;
    fflush(stdout);
    cin >> sm;
    if(sm == "Vacant") return 0;
    if((m-l) % 2) {
      if(sl == sm) {
        r = m; sr = sm;
      } else {
        l = m; sl = sm;
      }
    } else {
      if(sl == sm) {
        l = m; sl = sm;
      } else {
        r = m; sr = sm;
      }
    }
  }
  return 0;
}