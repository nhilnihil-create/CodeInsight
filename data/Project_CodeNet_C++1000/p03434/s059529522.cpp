#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a = 0, b = 0, ans, x;
  cin >> n;
  vector<int> card(n);
  for (int i = 0; i < n; i++) {
    cin >> x;
    card.at(i) = x;
  }
  sort(card.begin(), card.end());
  reverse(card.begin(), card.end());
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) a += card.at(i);
    else b += card.at(i);
  }
  ans = a - b;
  cout << ans << endl;
}