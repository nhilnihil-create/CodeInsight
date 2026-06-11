#include <bits/stdc++.h>
using namespace std;

int ans = 0;
vector<int> cnt(13, 0);

void func(int n, long long bit) {
  if (n == 13) {
    vector<int> tmp;
    for (int i = 0; i <= 24; i++) {
      if ((bit >> i) & 1) tmp.push_back(i);
    }
    int L = tmp.size();
    int diff = 24;
    for (int i = 1; i < L; i++) {
      diff = min(diff, tmp.at(i) - tmp.at(i-1));
    }
    ans = max(ans, diff);
    return;
  }
  if (cnt.at(n) == 0) {
    func(n+1, bit);
  }
  else if (cnt.at(n) == 1) {
    func(n+1, bit + (1LL << n));
    func(n+1, bit + (1LL << (24-n)));
  }
  else {
    func(n+1, bit + (1LL << n) + (1LL << (24-n)));
  }
}

int main() {
  int N; cin >> N;
  for (int i = 0; i < N; i++) {
    int d; cin >> d;
    cnt.at(d)++;
  }
  if (cnt.at(0) >= 1 || cnt.at(12) >= 2) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= 11; i++) {
    if (cnt.at(i) >= 3) { cout << 0 << endl; return 0; }
  }
  long long bit = (1LL << 24) + 1;
  func(1, bit);
  cout << ans << endl;
}