#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
 
  vector<int> cards(N+1);
  
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    cards.at(i) = a;
  }
  
   sort(cards.begin(), cards.end()); 
   reverse(cards.begin(), cards.end());
  
  int Alice = 0;
  int Bob = 0;
  
  for (int i = 0; i < N; i += 2) {
    Alice += cards.at(i);
  }
  
  for (int i = 0; i < N; i += 2) {
    Bob += cards.at(i+1);
  }
  
  cout << Alice - Bob << endl;
    
 }
