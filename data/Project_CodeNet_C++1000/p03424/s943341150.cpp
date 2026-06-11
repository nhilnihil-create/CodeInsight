#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string X;
    cin >> X;
     
    if (X=="Y") {
      cout << "Four" << endl;
      break;}
    
    else if (i== N-1 && X !="Y") {
      cout << "Three" << endl;}
    
   }
      
}