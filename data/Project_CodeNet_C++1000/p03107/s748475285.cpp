#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int length = S.size();
  int zero = 0;
  int one = 0;

  for(int i=0; i<length; i++) {
    if(S.at(i) == '0') zero++;
    else if(S.at(i) == '1') one++;
  }

  cout << 2 * min(zero, one) << endl;
  return 0;
}
