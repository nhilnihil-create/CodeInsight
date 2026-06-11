#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int i, N;
  cin >> N;
  
  for (i = 0; i < N; i++) {
    string op;
    cin >> op;
    
    if (op == "Y") {
      break;
    }
  }
  
  if (i == N) {
    cout << "Three" << endl;
  }
  
  else {
    cout << "Four" << endl;
  }
  
}
