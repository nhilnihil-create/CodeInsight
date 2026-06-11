#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int>A(4);
  for (int i = 0; i < 4; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  if (A.at(0) == 1 && A.at(1) == 4 && A.at(2) == 7 && A.at(3) == 9){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}

