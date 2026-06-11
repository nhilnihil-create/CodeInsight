#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;
  vector<int> cnt(3);
  cnt[0] = A+B;
  cnt[1] = A-B;
  cnt[2] = A*B;
  sort(cnt.begin(), cnt.end());
  cout << cnt[2] <<endl;
}
