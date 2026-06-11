#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int N;
  cin >> N;
  vector<int> v;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    sum += a;
    if (a > b) v.push_back(b);
  }

  if (v.size() == 0) {
    cout << 0 << endl;
    return 0;
  }

  sort(v.begin(), v.end());

  cout << sum - v[0] << endl;
  return 0;
}
