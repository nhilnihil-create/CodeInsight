#include <bits/stdc++.h>
using namespace std;

int main() {
  int price = 700;
  string s;
  cin >> s;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == 'o') {
      price+= 100;
    }
  }
  cout << price << endl;
}