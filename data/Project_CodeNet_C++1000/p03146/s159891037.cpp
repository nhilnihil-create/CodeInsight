#include <bits/stdc++.h>
using namespace std;


int main() {
  int m; cin >> m;
  int ans = 0;
  while(true){
    ans++;
    if(m == 4 || m == 2 || m == 1) break;
    if(m%2==0) m /= 2;
    else m = 3*m+1;
  }
  cout << ans+3 << endl;
}
