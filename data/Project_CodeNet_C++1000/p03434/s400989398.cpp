#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<int> cards(N);
  for (int n = 0; n < N; n++) {
    cin >> cards.at(n);
  }
  
  sort(cards.begin(), cards.end());
  reverse(cards.begin(), cards.end());
  
  int alice = 0;
  int bob = 0;
  for (int n = 0; n < N; n++) {
    if (n % 2 == 0) {
      alice += cards.at(n);
    } else {
      bob += cards.at(n); 
    }
  }
  
  cout << alice - bob << endl;
}
