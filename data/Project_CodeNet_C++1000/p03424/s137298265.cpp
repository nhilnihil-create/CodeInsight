#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  bool swi = false;
  for (int i = 0; i < N; i++) {
    char x;
    cin >> x;
    
    if (x == 'Y')
      swi = true;
  }
  
  if(swi)
    cout << "Four" << endl;
  else
    cout << "Three" << endl;
}