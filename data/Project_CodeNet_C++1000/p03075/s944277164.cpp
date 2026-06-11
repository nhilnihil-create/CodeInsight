#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 5;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int K;
  cin >> K;
  cout << ((A.at(4) - A.at(0) > K) ? ":(" : "Yay!") << "\n";
}