#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int P = 1;
  
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    
      if (S == "Y") {
        P *= 0;
      }
    
      else if (S != "Y") {
        P *= 1;
      }
  }
    if (P == 0)
      cout << "Four" << endl;
    
    else if (P == 1)
      cout << "Three" << endl;
}
