#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> ans;
  for (int i = 1; 5 * i + 1 <= 55555; i++) {
    bool P = true;
    for (int j = 2; j * j <= 5 * i + 1; j++) {
      if ((5 * i + 1) % j == 0) {
        P = false;
        break;
      }
    }
    if (P) ans.push_back(5 * i + 1);
    if (ans.size() == N) break;
  }
  for (int i = 0; i < N; i++) cout << ans.at(i) << " ";
  cout << endl;
}