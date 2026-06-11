#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int a, b = 0;
  for(int i = 0; i < S.size(); i++) {
    if(S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
      a++;
    }
    else {
      b = max(a,b);
      a = 0;
    }
    if(i == S.size()-1) {
      b = max(a,b);
    }
  }
  cout << b << endl;
}
