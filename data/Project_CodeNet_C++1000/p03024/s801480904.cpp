#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int w=0;
  for(int i=0;i<s.size();i++) {
    if(s[i]=='o') {
      w++;
    }
  }
  if(15-s.size()+w>7) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}