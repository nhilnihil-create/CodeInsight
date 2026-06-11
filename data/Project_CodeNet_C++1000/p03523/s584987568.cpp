#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int N = s.size();
  s += "AAAAA";
  if (N > 9 || N < 5) {
    cout << "NO" << endl;
    return 0;
  } 
  int sec = 0;
  if (s[0] == 'A' && s[1] == 'K' && s[2] == 'I' && s[3] == 'H') {
    sec = 4;
  }
  else if (s[0] == 'K' && s[1] == 'I' && s[2] == 'H') {
    sec = 3;
  }
  else {
    cout << "NO" << endl;
    return 0;
  }
  
  if (s[sec] == 'A' && s[sec+1] == 'B') {
    sec += 2;
  }
  else if (s[sec] == 'B') {
    sec++;
  }
  else {
    cout << "NO" << endl;
    return 0;
  }
  
  if (s[sec] == 'A' && s[sec+1] == 'R') {
    sec += 2;
  }
  else if (s[sec] == 'R') {
    sec++;
  }
  else {
    cout << "NO" << endl;
    return 0;
  }
  
  if (N-sec == 0) {
    cout << "YES" << endl;
    return 0;
  }
  if (N-sec == 1) {
    if (s[sec] == 'A') {
      cout << "YES" << endl;
      return 0;
    }
  }
  
  cout << "NO" << endl;
  
  return 0;
}