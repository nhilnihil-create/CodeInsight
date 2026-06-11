#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N;
  cin >> N;
  
  vector<int> card(N);
  
  for (int i = 0; i < N ; i++) {
    cin >> card.at(i);
  }
  
  int M1 = 0;
  int M2 = 0;
  int M3 = 0;
  
  for (int i = 0; i < N ; i++) {
    for (int j = 0; j < N ; j++) {
      if (card.at(j) > M2) {
        M2 = card.at(j);
        M3 = j;
      }
    }
    
    card.at(M3) = 0;
    
    if (i % 2 == 0) {
      M1 += M2;
    }
    else {
      M1 -= M2;
    }
    
    M2 = 0;
    M3 = 0;
    
  }
  
  cout << M1 << endl;
  
}