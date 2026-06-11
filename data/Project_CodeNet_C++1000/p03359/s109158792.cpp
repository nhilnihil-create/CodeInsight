#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  cin >> a >> b;
  bool j=false;
  if (b < a) {
    j = true;
  }
  int x=a;
  if (j) {
    x--;
  }
  cout << x << endl;
}