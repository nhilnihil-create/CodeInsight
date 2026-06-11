#include<bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int m = 0,b = 0;
  
  for(int i = 0; i < S.size();i++) {
  	if(S.at(i) == 'o') m++;
  }
  
  int rest = 15 - S.size();
  if(m + rest >= 8) {
  cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
  
}