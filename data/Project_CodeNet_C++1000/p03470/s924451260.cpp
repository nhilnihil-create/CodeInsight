#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> SE;
  while (cin >> N) SE.insert(N);
  cout << SE.size() << "\n";
}