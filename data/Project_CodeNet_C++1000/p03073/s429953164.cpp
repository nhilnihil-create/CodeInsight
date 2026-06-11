#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  int a = 0, b = 0;
  for (int i = 0; i < S.size(); i++) {
    if (i % 2 == 0 && S.at(i) == '1') {
      a++;
    }
    if (i % 2 == 1 && S.at(i) == '0') {
      a++;
    } 
    if (i % 2 == 1 && S.at(i) == '1') {
      b++;
    }
    if (i % 2 == 0 && S.at(i) == '0') {
      b++;
    } 
  }
  cout << min(a, b) << endl;
}
  