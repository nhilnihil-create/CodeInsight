#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  string s = "";
  while(n) {
    if(n%2) {
      n--;
      s +="1";
    }
    else s += "0";
    n /= (-2);
  }
  reverse(s.begin(), s.end());
  cout << (s.empty() ?"0" :s) << "\n";
}