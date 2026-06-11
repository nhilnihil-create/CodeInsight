#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> cnt(10, 0);
  for (int i = 0; i < 4; i++) {
    int N; cin >> N;
    cnt.at(N)++;
  }
  if (cnt.at(1) > 0 && cnt.at(9) > 0 && cnt.at(7) > 0 && cnt.at(4) > 0) {
    cout << "YES" << endl;
  }
  else cout << "NO" << endl;
}