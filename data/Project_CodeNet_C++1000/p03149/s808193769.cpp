#include<iostream>
using namespace std;
int main () {
  char a[4];
  cin >> a[0] >> a[1] >> a[2] >> a[3];
  int p = 0;
  int q = 0;
  int r = 0;
  int s = 0;
  for (int i = 0; i < 4; i ++) {
    switch(a[i]) {
      case '1': p ++; break;
      case '9': q ++; break;
      case '7': r ++; break;
      case '4': s ++; break;
    }
  }
  if (p == 1 && q == 1 && r == 1 && s == 1) cout << "YES" << endl;
  else cout << "NO" << endl;
}
  
