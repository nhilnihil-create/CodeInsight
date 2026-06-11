#include <bits/stdc++.h>
using namespace std;
int main() {
  int x,n,a,b,counter;
  counter = 0;
  cin >> n;
  vector<int> vecx(0);
  for (int j = 0; j < n; j++) {
   cin >> x;
   vecx.push_back(x);
  }
  sort(vecx.begin(), vecx.end());
  for (int j = 0; j < n-1; j++) {
    a = vecx.at(j);
    b = vecx.at(j+1);
    if (a == b) {
      counter++;
    }
  }
  cout << n-counter << endl;
}