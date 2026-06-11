#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N;
  string A, R = "Three";
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A;
    if (A == "Y") {
      R = "Four";
      break;
      }
   }
  
   cout << R << endl;
}

