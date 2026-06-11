#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin>>a>>b;
  int m=max(a,b);
  if (a==b) {
    cout << 2*a << endl;
  }
  else {
    cout << 2*m-1 << endl;
  }
}
