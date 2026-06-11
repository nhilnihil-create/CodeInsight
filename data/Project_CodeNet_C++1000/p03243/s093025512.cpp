#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  while (true) {
    string tmp = to_string(N);
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    if (tmp.size() == 1) return cout << N << "\n", 0;
    N++;
  }
}