#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  string s;
  cin >> a >> b >> s;
  
  vector<char> data(s.size());
  for (int i=0; i<s.size(); i++) {
    data.at(i) = s.at(i);
  }

  for (int i=0; i<a; i++) {
    if(isdigit(data.at(i)) != true) {
      cout << "No" << endl;
      goto SKIP;
    }
  }

  if(data.at(a) != '-') {
    cout << "No" << endl;
    goto SKIP;
  }

  for (int i=0; i<b; i++) {
    if(isdigit(data.at(i+a+1)) != true) {
      cout << "No" << endl;
      goto SKIP;
    }
  }

  cout << "Yes" << endl;
  SKIP:
  return 0;
}