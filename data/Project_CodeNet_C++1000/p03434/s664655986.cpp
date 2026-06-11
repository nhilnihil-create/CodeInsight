#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,b,c;
  b = 0;
  c = 0;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(),a.end());
  reverse(a.begin(),a.end());
  for(int i = 0; i < n; i++) {
    if(i % 2 == 0) {
      b = b + a.at(i);
    }
    else {
      c = c + a.at(i);
    }
  }
  cout << b - c << endl;
}
