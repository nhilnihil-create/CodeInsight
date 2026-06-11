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
  
  int alice = 0;
  int bob = 0;
  
  bool first = true;
  while (!card.empty()) {
    if (first) {
      alice += card.back();
      first = false;
    } else {
      bob += card.back();
      first = true;
    }
    card.pop_back();
  }
  
  cout << alice - bob << endl;
}
