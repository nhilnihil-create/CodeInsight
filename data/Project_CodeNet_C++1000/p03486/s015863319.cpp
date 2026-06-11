#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int x = s.size();
  int y = t.size();
  vector<char> a(x), b(y);
  for (int i = 0; i < x; i++) {
    a.at(i) = s.at(i);
  }
  
  for (int i = 0; i < y; i++) {
    b.at(i) = t.at(i);
  }
  
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  
  if (x > y) {
    for (int i = 0; i < y; i++) {
      if (a.at(i) < b.at(i)) {
        cout << "Yes" << endl;
        break;
      }
      if (a.at(i) > b.at(i)) {
        cout << "No" << endl;
        break;
      }
      if (a.at(i) == b.at(i)) {
        if (i == y-1) {
          cout << "No" << endl;
        }
      }
    }
  }
  else {
    for (int i = 0; i < x; i++) {
      if (a.at(i) < b.at(i)) {
        cout << "Yes" << endl;
        break;
      }
      if (a.at(i) > b.at(i)) { 
        cout << "No" << endl;
        break;
      }
      if (a.at(i) == b.at(i)) {
        if (i == x-1) {
          if (x == y) {
            cout << "No" << endl;
          }
          if (x != y) {
            cout << "Yes" << endl;
          }
        }
      }
    }
  }
}