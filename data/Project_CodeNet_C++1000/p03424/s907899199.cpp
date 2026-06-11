#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, y=0;
  cin >> N;
  
  for (int i=0; i<N; i++) {
    string S;
    cin >> S;
    
    if (S=="Y") {
      y++;
    }
  }
  
  if (y != 0) {
    cout << "Four" << endl;
  }
  else {
    cout << "Three" << endl;
  }
}