#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, D, M, T;
  cin >> N;
  multiset<int> S;
  while (N-- && cin >> D) S.insert(D);
  cin >> M;
  while (cin >> T) {
    if (!S.count(T)) return cout << "NO" << "\n", 0;
    S.erase(S.find(T));
  }
  cout << "YES" << "\n";
}