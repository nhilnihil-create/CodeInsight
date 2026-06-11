#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }

  int pa = a[0], b = 1, ans = 0;
  for (int i = 1; i < N; ++i) {
    if (a[i] == pa) {
      ++b;
    } else {
      ans += b / 2, pa = a[i], b = 1;
    }
  }
  ans += b / 2;

  cout << ans << endl;
}
