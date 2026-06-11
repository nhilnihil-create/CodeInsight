#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int total = 0;
  for(int i=0; i < (int)S.size(); i++) {
      if(S.at(i) == '+') {
          total += 1;
      }
      else{
          total -= 1;
      }
  }
  cout << total << endl;
}
