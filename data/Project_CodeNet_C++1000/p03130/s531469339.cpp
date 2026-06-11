#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<int>A(6);
  vector<int>B(4,0);
  for (int i = 0; i < 6; i++) {
    cin >> A.at(i);
    B.at(A.at(i)-1)++;
  }
  sort(B.begin(), B.end());
  if (B.at(0) == 1 && B.at(3) == 2){
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}
  
    