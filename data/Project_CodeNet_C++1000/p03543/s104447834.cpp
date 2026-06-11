#include <bits/stdc++.h>
using namespace std;

int returnGood (string gi, int start) {
  char c = gi[start];
  int i;

  for (i = start ; i < (int)(gi.size ()) ; i++) {
    if (c == gi[i]) {
      continue;
    } else 
      break;
  }

  if (i - start > 2) {
    cout << "Yes" << endl;
    return 0;
  } else {
    return 1;
  }

}

int main() {

  string GoodInteger; 
  cin >> GoodInteger;

  if (returnGood (GoodInteger, 0)) {
    if (returnGood (GoodInteger, 1)) {
      cout << "No" << endl;
    }
  }

}

