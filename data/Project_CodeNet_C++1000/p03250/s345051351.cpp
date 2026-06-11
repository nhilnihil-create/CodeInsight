#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int ans;
  vector<int> A(3);
  for (int i=0; i<3; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(),A.end());
  ans=A.at(0)+A.at(1)+10*A.at(2);
  cout << ans << endl;
}
