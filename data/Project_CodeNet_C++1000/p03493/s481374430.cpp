#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string S;
  cin >> S;
  int count = 0;
  if(S.at(0) == '1'){
    count++;
  }
  if(S.at(1) == '1'){
    count++;
  }
  if(S.at(2) == '1'){
    count++;
  }
  cout << count << endl;
}