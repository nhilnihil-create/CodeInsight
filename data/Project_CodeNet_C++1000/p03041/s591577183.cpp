#include <bits/stdc++.h>
using namespace std;

int main() {
  int A,B;
  cin >> A >> B;
  string S;
  cin >> S;
  for (int i = 0; i < A; i++) {
    if (i == B - 1) {
      if (S.at(i) == 'A')
        cout << 'a';
      if (S.at(i) == 'B')
        cout << 'b';
      if (S.at(i) == 'C')
        cout << 'c';
    }
    else
      cout << S.at(i);
  }
  cout << endl;  
 
}