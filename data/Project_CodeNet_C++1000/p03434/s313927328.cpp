#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> cards(N);
  
  for (int i = 0; i < N; i++) cin >> cards.at(i);
  
  sort(cards.begin(),cards.end(),greater<int>());
  
  int Alice = 0;
  int Bob = 0;
  
  for (int i = 0; i < N; i += 2) Alice += cards.at(i);
  for (int i = 1; i < N; i += 2) Bob += cards.at(i);
  
  cout << Alice - Bob << endl;
}