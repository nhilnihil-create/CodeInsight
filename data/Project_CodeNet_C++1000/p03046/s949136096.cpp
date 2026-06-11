#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;

int main(){
  int m, k;
  cin >> m >> k;
  if(m == 1) {
    if(k >= 1) cout << -1 << endl;
    else if(k == 0) cout << 1 << " " << 1 << " " << 0 << " " << 0 << endl;  
    return 0;
  }
  if(k >= (1<<m)) {
    cout << -1 << endl;
    return 0;
  }
  rep(i,1<<m) {
    if(i != k) cout << i << " ";
  }
  cout << k << " ";
  for(int i = (1<<m)-1; i >= 0; i--) {
    if(i != k) cout << i << " ";
  }
  cout << k << endl;
  return 0;
}