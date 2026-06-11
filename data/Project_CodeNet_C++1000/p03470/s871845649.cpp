#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  vector<int> r(100);
  cin >> n;
  a = n;
  for(int i=0;i<n;i++) {
    cin >> r.at(i);
  }
  for(int i=0;i<n;i++) {
    if (r.at(i) == 0) {
      continue;
    }
    for(int j=i+1;j<n;j++) {
      if(r.at(i) == r.at(j)) {
        a--;
        r.at(j) = 0;
      }
    }
  }
  cout << a << endl;
  return 0;
}