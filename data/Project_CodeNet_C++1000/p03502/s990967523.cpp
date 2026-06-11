#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n,a,s = 0;
  cin >> n;
  a=n;
  while (a!=0) {
    s += a-a/10*10;
    a /= 10;
  }
  if (n%s==0) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}