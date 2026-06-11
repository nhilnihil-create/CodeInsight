#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> c(100);
  int n, a, b;
  cin >> n;
  for(int i=0;i<n;i++) {
    cin >> c.at(i);
  }
  for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
      if(c.at(i) < c.at(j)) {
        b=c.at(i);
        c.at(i) = c.at(j);
        c.at(j) = b;
      }
    }
  }
  a=0;
  for(int i=0;i<n;i+=2) {
    a+=c.at(i)-c.at(i+1);
  }
  cout << a << endl;
  return 0;
}

