#include <bits/stdc++.h>
using namespace std;

int main(){
  string ABCD;
  cin >> ABCD;
  vector<char> op(3);
  
  for (int i = 0; i < (1 << 3); i++) {
    int tmp = ABCD.at(0) - '0';
    for (int j=0; j<3; j++){
      if (i & 1<<j) {
        tmp += ABCD.at(j+1) - '0';
        op.at(j) = '+';
      }
      else {
        tmp -= ABCD.at(j+1) - '0';
        op.at(j) = '-';
      }
    }
  if (tmp == 7) break;
  }
    cout << ABCD.at(0);
    for (int k = 0; k < 3; k++){
     cout << op.at(k) << ABCD.at(k+1);
    }
    cout << "=7" << endl;
}