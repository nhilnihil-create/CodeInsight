#include <bits/stdc++.h>
using namespace std;
using pp=pair<int, int>;

int main() {
  int a,b,x;
  cin>> a >> b >> x;
  if (x<=a+b && x>=a) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
