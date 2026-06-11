#include <bits/stdc++.h>
using namespace std;

int main() {
  string str;
  int cntZero = 0;
  int cntOne = 0;
  
  cin >> str;
  
  for(int i = 0; i < str.size(); i++){
    if(str.at(i) == '0') cntZero++;
    else cntOne++;
  }
  
  cout << min(cntZero, cntOne) * 2;
}
