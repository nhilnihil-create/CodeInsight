#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> S;
    if (S == "Y") {
      cout << "Four" << endl;
      break;
    }
    else if (i+1 < N)
      continue;
    cout << "Three" << endl;
  }
}