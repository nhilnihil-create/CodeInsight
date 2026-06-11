#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int64_t INF =1e18;
int main () {
  int n1,n2,n3,n4;
  cin >> n1>>n2>>n3>>n4;
  
  if ((n1*n1 + n2*n2 + n3*n3 + n4*n4) == (1*1 + 7*7 + 9*9 + 4*4))
  {
    cout << "YES" << endl;
  }
  else
  cout << "NO" << endl;
}
