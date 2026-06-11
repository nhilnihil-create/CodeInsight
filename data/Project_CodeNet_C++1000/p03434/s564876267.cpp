#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> card(N);
  
  for (int i = 0; i < N; i++) {
    cin >> card.at(i);
  }
  
  sort(card.begin(), card.end());
  reverse(card.begin(), card.end());
  
  bool ab = true;
  int Ap = 0;
  int Bp = 0;
  
  for (int i = 0; i < N; i++) {
    
    if (ab) {
      Ap += card.at(i);
      ab = false;
    }
    else {
      Bp += card.at(i);
      ab = true;
    }
  }
  
  cout << Ap - Bp << endl;
  
}