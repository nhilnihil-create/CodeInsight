#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long n,m;
  cin >> n >> m;
  
  long l;
  if (n >= 2 && m >= 2) {
    l = (n - 2) * (m - 2);
  } else {
    if (n == m) {
      l = 1;
    } else if (n == 1){
      l = m - 2;
    } else {
      l = n - 2;
    }
  }
  cout << l << endl;
}