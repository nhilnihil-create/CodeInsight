#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;
const int64_t INF =1e18;

int a[10];
int main () {
  
  for (int i=0; i<4; i++) {
    int n; cin >> n;
    a[n]++;
  }
  if (a[1] == 1 && a[4] == 1 && a[7] == 1 && a[9] == 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}
