#include <bits/stdc++.h>
using namespace std;
 
int main() {
  
  int N;
  cin >> N;
  
  vector<string> bluestring(N);
  
  for (int i = 0; i < N ; i++) {
    cin >> bluestring.at(i);
  }
  
  int M;
  cin >> M;
  
  vector<string> redstring(M);
  
  for (int i = 0; i < M ; i++) {
    cin >> redstring.at(i);
  }
  
  int YEN = 0;
  int C = 0;
  
  for (int i = 0; i < N ; i++) {
    
    for (int j = 0; j < N ; j++) {
      if (bluestring.at(i) == bluestring.at(j)) {
        C++;
      }
    }
    
    for (int j = 0; j < M ; j++) {
      if (bluestring.at(i) == redstring.at(j)) {
        C--;
      }
    }
    
    if (C>YEN) {
      YEN = C;
    }
    
    C = 0;
  }
  
  cout << YEN << endl;
}