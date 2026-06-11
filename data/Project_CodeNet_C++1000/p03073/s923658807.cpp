#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int count1 = 0;
  int count2 = 0;
  for(int i = 0; i < S.size(); i++) {
    if(i % 2 == 0) {
      if(S.at(i) == '0') {
        count2++;
      }
      else {
        count1++;
      }
    }
    else {
      if(S.at(i) == '0') {
        count1++;
      }
      else {
        count2++;
      }
    }
  }
  cout << min(count1, count2) << endl;
}