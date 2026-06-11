#include<bits/stdc++.h>
using namespace std;
int main() {
  int a, b; cin >> a >> b;
  string s; cin >> s;
  bool acceptable = 1;
  set<char> numbers;
  numbers.insert('0');
  numbers.insert('1');
  numbers.insert('2');
  numbers.insert('3');
  numbers.insert('4');
  numbers.insert('5');
  numbers.insert('6');
  numbers.insert('7');
  numbers.insert('8');
  numbers.insert('9');
  for(int i = 0; i < a + b + 1; i++) {
    if(i == a) {
      if(s.at(i) != '-') {
        acceptable = 0;
      }
    }
    else{
      if(!(numbers.count(s.at(i)))) {
        acceptable = 0;
      }
    }
  }
  if(acceptable) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}