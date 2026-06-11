#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, a, a_sum = 0, b_sum = 0;

  cin >> N;
  vector<int> card(N);

  for (int i = 0; i < N; i++) {
    cin >> a;
    card.at(i) = a;
  }
  
  sort(card.begin(), card.end(), greater<int>());

  for (int i = 0; i < N; i++) {
    if (i == 0 || i % 2 == 0) {
      a_sum += card.at(i);
    }
    else {
      b_sum += card.at(i);
    }
    
  }
    cout <<  a_sum - b_sum << endl;
}
