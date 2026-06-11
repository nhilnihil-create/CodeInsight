#include <bits/stdc++.h>
using namespace std;

int main() {
  int input;
  vector<int> A(4);
  cin >> input;

  A.at(0) = input/1000; input -= A.at(0)*1000;
  A.at(1) = input/100; input -= A.at(1)*100;
  A.at(2) = input/10; input -= A.at(2)*10;
  A.at(3) = input;

  for (int i = 0; i < (1 << 3); i ++) {
    bitset<3> tmp(i);
    int sum = A.at(0);
    vector<char> op(3);
    for (int j = 0; j < 3; j++) {
      if(tmp.test(j)) {
        sum+=A.at(j+1);
        op.at(j)='+';
      } else {
        sum-=A.at(j+1);
        op.at(j)='-';
      }
    }
    if (sum == 7) {
    for(int step = 0; step < 3; step++) {
      cout << A.at(step) << op.at(step);
    }
    cout << A.at(3) << "=" << "7" << endl;
    break;
    }
  }
}