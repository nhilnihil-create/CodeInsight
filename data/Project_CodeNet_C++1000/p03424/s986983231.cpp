#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  bool flag;
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> S;
    if(S == "Y") {
      flag = true;
      break;
    } else {
      flag = false;
      continue;
    }
  }
  if(flag == true) {
    cout << "Four" << endl;
  } else if(flag == false) {
    cout << "Three" << endl;
  }
  return 0;
}
