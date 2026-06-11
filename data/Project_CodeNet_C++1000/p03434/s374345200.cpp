#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end());
  reverse(a.begin(), a.end());
  int Alice = 0, Bob = 0;
  for (int k = 0; k < a.size(); k++) {
    if (k % 2 == 0) {
      Alice += a.at(k);
    }
    else {
      Bob += a.at(k);
    }
  }
  cout << Alice - Bob << endl;
}
