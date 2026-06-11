#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  for(int i=0;i<2;i++){
    if(S.at(i)==S.at(i+1) && S.at(i+1)==S.at(i+2)){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}