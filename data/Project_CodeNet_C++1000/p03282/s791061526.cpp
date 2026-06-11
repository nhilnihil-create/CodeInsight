#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  int k;
  cin >> s >> k;
  if(s.at(0) == '1'){
    for(int i=0;i<k;i++){
      if(s.at(i) != '1'){
        cout << s.at(i);
        break;
      }
      else if(i == k-1)
        cout << 1;
    }
  }
  else
    cout << s.at(0);
}