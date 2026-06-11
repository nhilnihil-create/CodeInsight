#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> SE;
  SE.insert(1);
  for (int i = 2; i * i < N; i++) {
    for (int j = i; j <= N; j *= i) {
      SE.insert(j);
    }
  }
  for (int i = N; i >= 1; i--) {
    if (SE.count(i)) return cout << i << "\n", 0;
  }
}