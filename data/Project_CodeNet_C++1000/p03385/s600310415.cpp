#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  cout << (s.find('a', 0) != string::npos && s.find('b', 0) != string::npos && s.find('c', 0) != string::npos ? "Yes" : "No") << endl;
}