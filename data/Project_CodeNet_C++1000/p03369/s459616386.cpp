#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int p = 700;
  int a = S.size();
  
  for (int i = 0; i < a; i++) {
    if (S.at(i) == 'o') p += 100;    
  }
  
  cout << p << endl;
}
