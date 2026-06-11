#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int64_t INF =1e18;

int a[10];
int main () {
/* 方法１：
  int n1,n2,n3,n4;
  cin >> n1>>n2>>n3>>n4;
  if ((n1*n1 + n2*n2 + n3*n3 + n4*n4) == (1*1 + 7*7 + 9*9 + 4*4))
*/

/* 方法2：
  for (int i=0; i<4; i++) {
    int n; cin >> n;
    a[n]++;
  }
  if (a[1] == 1 && a[4] == 1 && a[7] == 1 && a[9] == 1)
*/
//方法3：
  
  vector<int>n(4);
  for (int i=0; i<4; i++) cin >>n[i];
  
  sort(n.begin(), n.end());
  
  if (n[0] = 1 && n[1] == 4 && n[2] == 7 && n[3] == 9)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
