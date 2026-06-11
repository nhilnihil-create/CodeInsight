#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  if(s.at(0) != 'A') {
    cout << "WA" << endl;
    return 0;
  }
  int n = s.size();
  int count = 0;
  for(int i=2; i<n-1; i++) {
    if(s.at(i) == 'C') {
      count++;
    } else if(isupper(s.at(i))) {
      cout << "WA" << endl;
      return 0;
    }
  }
  if(isupper(s.at(1)) || isupper(s.at(n-1))) {
    cout << "WA" << endl;
    return 0;
  }
  if(count == 1) {
    cout << "AC" << endl;
  } else {
    cout << "WA" << endl;
  }
}