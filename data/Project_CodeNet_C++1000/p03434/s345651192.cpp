#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int S = 0;
  cin >> N;
  vector<int> cards(N);
  
  for (int i = 0; i < N; i++) {
    cin >> cards.at(i);
  }
  
  sort(cards.begin(), cards.end());
  reverse(cards.begin(), cards.end());
  
  if (N % 2 == 0) {
    for (int i = 0; i < N; i+=2) {
      S += (cards.at(i) - cards.at(i + 1));
    }
  }
  else {
    for (int i = 0; i < N - 1; i+=2) {
      S += (cards.at(i) - cards.at(i + 1));
    }
    S += cards.at(N - 1);
  }
  
  cout << S << endl;
}