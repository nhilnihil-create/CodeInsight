#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  
  vector<int> m(N);
  for (int i = 0; i < N; i++) cin >> m.at(i);

  int amount = X;
  int count = N;
  for (int i = 0; i < N; i++) amount -= m.at(i);
  
  sort(m.begin(), m.end());
  
  for (int i = 0; i < N; i++) {
    if (amount - m.at(i) < 0) {
      break;
    }
    else {
      int s = amount / m.at(i);
      count += s;
      amount %= m.at(i); 
    }
  }
  cout << count << endl;
}