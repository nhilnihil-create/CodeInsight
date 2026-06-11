#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int N;  cin >> N;
  vector<int> a(N);

  for (int i = 0; i < N; ++i) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());

  int ret = 0;
  for (int i = 0; i < N; ++i) ret += a[i] * (i & 1 ? -1 : 1);

  cout << ret << endl;

  return 0;
}