#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int X;
  cin >> X;
  int m=0, n;
  if (X==1) {m=1;}
  else {
    for (int i=2; i<=sqrt(X); i++) {
      n=i;
      while (n*i<=X) {
        n*=i;
      }
      m=max(m, n);
    } 
  }
  cout << m << endl;
}
