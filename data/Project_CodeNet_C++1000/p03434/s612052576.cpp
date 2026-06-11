#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> card(N);
  for (int i = 0; i < N; i++) {
    cin >> card[i];
  }
  sort(card.begin(), card.end(), greater<int>());
  
  int Ap = 0, Bp = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) Ap += card[i];
    else Bp += card[i];
  }
  cout << Ap - Bp << endl;
}