#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin >> X;
 
  vector<int> M(51);
  for (int i = 0; i < 31; i++) {
    M.at(i) = (i + 1)*(i + 1);
  }
  for (int i = 1; i < 10; i++) {
    M.at(i+30) = (i + 1)*(i + 1)*(i + 1);
  }
  for (int i = 1; i < 5; i++) {
    M.at(i+39) = (i + 1)*(i + 1)*(i + 1)*(i + 1);
  }
  for (int i = 1; i < 3; i++) {
    M.at(i+43) = (i + 1)*(i + 1)*(i + 1)*(i + 1)*(i + 1);
  }
  for (int i = 1; i < 3; i++) {
    M.at(i+45) = (i + 1)*(i + 1)*(i + 1)*(i + 1)*(i + 1)*(i + 1);
  }
  M.at(48) = 128;
  M.at(49) = 256;
  M.at(50) = 512;
  sort(M.begin(), M.end());
  
  int count = 0;
  int A;
  for (int i = X; i > 0; i--) {
    if (count == 1){
      break;
    }
    for (int j = 50; j >= 0; j--) {
      if (M.at(j) == i){
        count++;
        A = i;
        break;
      }
    }
  }
  cout << A << endl;
}

