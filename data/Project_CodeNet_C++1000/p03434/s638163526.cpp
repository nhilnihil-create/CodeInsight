#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N, Alice = 0, Bob = 0;
  vector<int> a(100);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  for (int j = 0; j < N; j+=2) {
    Alice += a.at(j);
  }
  for (int k = 1; k < N; k+=2) {
    Bob += a.at(k);
  }
    cout << abs(Bob - Alice) << endl;
}