#include <bits/stdc++.h>
using namespace std;


int main() {
  int n,k;
  
  string s;
  
  cin >> n >> k >> s;
  
  s.at(k-1) = s.at(k-1)+0x20;
  
  for(int i=0; i<s.size(); i++){
    cout << s.at(i);
  }
  
  
}