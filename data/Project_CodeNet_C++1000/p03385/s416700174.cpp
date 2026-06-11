#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int cntA = 0;
  int cntB = 0;
  int cntC = 0;
  cin >> str;
  
  for(int i = 0; i < 3; i++){
    if(str.at(i) == 'a') cntA++;
    else if(str.at(i) == 'b') cntB++;
    else if(str.at(i) == 'c') cntC++;
  }
  
  if(cntA == 1 && cntB == 1 && cntC == 1) cout << "Yes";
  else cout << "No";
}
